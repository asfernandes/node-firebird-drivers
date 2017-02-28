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
			'conditions': [
				[
					'OS == "linux"', {
						"cflags!": [ "-fno-exceptions" ],
						"cflags_cc!": [ "-fno-exceptions" ]
					}
				]
			]
		}
	]
}
