from conans import ConanFile, CMake, tools

class CppMath(ConanFile):
    author = "TNT Coders <tnt-coders@googlegroups.com>"
    build_requires = "catch2/3.0.0-1@tnt-coders/stable"
    default_options = {"shared": False}
    description = "C++ library containing common math utility functions"
    exports_sources = "CMakeLists.txt", "docs/*", "include/*", "src/*", "test/*"
    generators = "cmake", "cmake_paths"
    license = "GNU Lesser General Public License v3.0"
    name = "math"
    options = {"shared": [True, False]}
    settings = "os", "compiler", "build_type", "arch"
    topics = ("math")
    url = "https://github.com/tnt-coders/cpp-math"

    def configure(self):
        tools.check_min_cppstd(self, "17")

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()
        cmake.test()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = self.cpp_info.libs = tools.collect_libs(self)

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake