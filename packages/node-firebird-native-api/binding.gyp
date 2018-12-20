{
	"targets": [
		{
			"target_name": "addon",
			"sources": [
				"src/native/fb-native.cpp"
			],
			"include_dirs": [
				"<!(node -e \"require('nan')\")"
			],
			"cflags!": [ "-fno-exceptions" ],
			"cflags_cc!": [ "-fno-exceptions" ],
			'conditions': [
				[
					'OS == "win"', {
						"msvs_settings": {
							"VCCLCompilerTool": {
								"ExceptionHandling": 1
							}
						}
					},
					'OS == "mac"', {
						"xcode_settings": {
							"GCC_ENABLE_CPP_EXCEPTIONS": "YES"
						}
					}
				]
			]
		},
		{
			 "target_name": "action_after_build",
			 "type": "none",
			 "dependencies": [ "<(module_name)" ],
			 "copies": [
				{
					"files": [ "<(PRODUCT_DIR)/<(module_name).node" ],
				  	"destination": "<(module_path)"
				}
			 ]
		}
	]
}
