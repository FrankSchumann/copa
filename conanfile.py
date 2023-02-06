from conan import ConanFile
from conan.tools.files import copy


class copaRecipe(ConanFile):
    name = "copa"
    version = "0.0.2"

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
        _src_component_folder = self.source_folder + '/include/component'
        _dst_component_folder = self.package_folder + '/include/copa/component'
        
        _src_factory_folder = self.source_folder + '/include/factory'
        _dst_factory_folder = self.package_folder + '/include/copa/factory'

        _src_mock_folder = self.source_folder + '/include/mock'
        _dst_mock_folder = self.package_folder + '/include/copa/mock'

        copy(self, "*.h", _src_component_folder, _dst_component_folder, keep_path=False)
        copy(self, "*.h", _src_factory_folder, _dst_factory_folder, keep_path=False)
        copy(self, "*.h", _src_mock_folder, _dst_mock_folder, keep_path=True)

    def requirements(self):
        self.requires("osal/0.0.2")
