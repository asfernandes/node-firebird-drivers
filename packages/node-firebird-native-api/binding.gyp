{
	"targets": [
		{
			"target_name": "addon",
			"sources": [
				"src/native/fb-native.cpp"
			],
			"include_dirs": [
				"<!@(node -p \"require('node-addon-api').include\")"
			],
			"cflags!": [ "-fno-exceptions" ],
			"cflags_cc!": [ "-fno-exceptions" ],
			"defines": [
				'NAPI_VERSION=4',
				'NAPI_EXPERIMENTAL'
			],
			"configurations": {
				"Release": {
					"defines": [
						"NDEBUG"
					]
				}
			},
			'conditions': [
				[
					'OS == "win"', {
						"msvs_settings": {
							"VCCLCompilerTool": {
								"ExceptionHandling": 1,
								"AdditionalOptions": ["/bigobj"]
							}
						},
						"defines": [
							"_HAS_EXCEPTIONS=1"
						]
					},
					'OS == "mac"', {
						"xcode_settings": {
							"GCC_ENABLE_CPP_EXCEPTIONS": "YES"
						}
					}
				]
			]
		}
	]
}
