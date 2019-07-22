from conans import ConanFile, Meson, tools
from scripts.meson_utils import generate_subproject

import os


class Morph(ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch', 'cppstd'

    requires = (
        'gtest/1.8.1@bincrafters/stable',
        'TBB/2019_U4@conan/stable'
    )

    generators = {}

    def create_meson_subprojects(self):
        subprojects_path = os.path.join(
            os.path.dirname(os.path.abspath(__file__)),
            'subprojects')

        if not os.path.exists(subprojects_path):
            os.mkdir(subprojects_path)
        
        deps = self.deps_cpp_info.deps

        for dependency_name in deps:
            lib_names = self.deps_cpp_info[dependency_name].libs
            lib_dirs = self.deps_cpp_info[dependency_name].lib_paths
            include_dirs = self.deps_cpp_info[dependency_name].include_paths

            project_dir = os.path.join(subprojects_path, dependency_name)
            project_file = os.path.join(project_dir, 'meson.build')

            if not os.path.exists(project_dir):
                os.mkdir(project_dir)

            with open(project_file, 'w', newline='') as project:
                payload = generate_subproject(dependency_name, lib_names, lib_dirs, include_dirs)
                project.writelines(payload)

    def build(self):
        self.create_meson_subprojects()

        defs = {
            "b_coverage": "true"
        }

        meson = Meson(self)
        meson.configure(build_dir='meson_build', defs=defs)
        meson.build()

    def package(self):
        self.copy("*.so", keep_path=False)
