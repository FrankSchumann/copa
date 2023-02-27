cmake_minimum_required( VERSION 3.15 )

project( copa 
		VERSION 0.0.0.5
		DESCRIPTION "Controller Platform" )

set( CMAKE_CXX_STANDARD 17 )

file( GLOB PROJECT_SOURCE_FILES "src/main.cpp" )

find_package( core CONFIG REQUIRED )
find_package( osal CONFIG REQUIRED )
find_package( runtime CONFIG REQUIRED )

add_executable( ${PROJECT_NAME} ${PROJECT_SOURCE_FILES} )

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  core::core
  osal::osal
)

# Create a simple configuration header
configure_file( config.h.in config.h )

# Include the configuration header in the build
target_include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR} ${core_INCLUDE_DIR} ${osal_INCLUDE_DIR} ${runtime_INCLUDE_DIR} )

set_target_properties( ${PROJECT_NAME} PROPERTIES ENABLE_EXPORTS 1 )

message( "CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}" )

IF(EXISTS "${WIND_CC_SYSROOT}/secureLoader/privatekey.pem")
	IF(EXISTS "${WIND_CC_SYSROOT}/secureLoader/publiccert.pem")
		add_custom_command(TARGET ${MY_TARGET} POST_BUILD
			COMMAND echo "start singtool command ..."
			COMMAND signtool --strip=all --key=${WIND_CC_SYSROOT}/secureLoader/privatekey.pem --cert=${WIND_CC_SYSROOT}/secureLoader/publiccert.pem --type=ELF ${MY_TARGET}
			COMMENT  "end singtool command ..."
		)
	ENDIF()
ENDIF()
