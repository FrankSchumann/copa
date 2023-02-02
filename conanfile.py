from conan import ConanFile
from conan.tools.files import copy


class copaRecipe(ConanFile):
    name = "copa"
    version = "0.0.1"

    # Optional metadata
    license = "<Put the package license here>"
    author = "<Put your name here> <And your email here>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of osal package here>"
    topics = ("<Put some tag here>", "<here>", "<and here>")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    exports_sources = "include/*"
    no_copy_source = True

    def package(self):
        # This will also copy tlude" folder
        copy(self, "*.h", self.source_folder, self.package_folder)

    def requirements(self):
        self.requires("osal/0.0.2")
