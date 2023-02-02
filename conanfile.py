from conan import ConanFile


class copaRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("osal/0.0.2")
        self.requires("runtime/0.0.2")
    
