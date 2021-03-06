project('harfbuzz', 'cpp')
library_version = '2.2.0'

src = [
	'src/hb-aat-layout.cc',
	'src/hb-aat-map.cc',
	'src/hb-blob.cc',
	'src/hb-buffer.cc',
	'src/hb-buffer-serialize.cc',
	'src/hb-common.cc',
	'src/hb-face.cc',
	'src/hb-fallback-shape.cc',
	'src/hb-font.cc',
	'src/hb-ft.cc',
	'src/hb-icu.cc',
	'src/hb-map.cc',
	'src/hb-ot-color.cc',
	'src/hb-ot-face.cc',
	'src/hb-ot-font.cc',
	'src/hb-ot-layout.cc',
	'src/hb-ot-map.cc',
	'src/hb-ot-math.cc',
	'src/hb-ot-name-language.cc',
	'src/hb-ot-name.cc',
	'src/hb-ot-shape-complex-arabic.cc',
	'src/hb-ot-shape-complex-default.cc',
	'src/hb-ot-shape-complex-hangul.cc',
	'src/hb-ot-shape-complex-hebrew.cc',
	'src/hb-ot-shape-complex-indic-table.cc',
	'src/hb-ot-shape-complex-indic.cc',
	'src/hb-ot-shape-complex-khmer.cc',
	'src/hb-ot-shape-complex-myanmar.cc',
	'src/hb-ot-shape-complex-thai.cc',
	'src/hb-ot-shape-complex-use-table.cc',
	'src/hb-ot-shape-complex-use.cc',
	'src/hb-ot-shape-complex-vowel-constraints.cc',
	'src/hb-ot-shape-fallback.cc',
	'src/hb-ot-shape-normalize.cc',
	'src/hb-ot-shape.cc',
	'src/hb-ot-tag.cc',
	'src/hb-ot-var.cc',
	'src/hb-set.cc',
	'src/hb-shape-plan.cc',
	'src/hb-shape.cc',
	'src/hb-shaper.cc',
	'src/hb-static.cc',
	'src/hb-subset-glyf.cc',
	'src/hb-subset-input.cc',
	'src/hb-subset-plan.cc',
	'src/hb-subset.cc',
	'src/hb-unicode.cc',
	'src/hb-warning.cc',
]

cpp_args = [
	'-DHAVE_OT',
	'-DHAVE_ICU_BUILTIN',
	'-DHAVE_ICU',
	'-DHAVE_FREETYPE',
	'-DHAVE_FT_FACE_GETCHARVARIANTINDEX'
]

if meson.get_compiler('cpp').get_id() != 'msvc'
	cpp_args += [
		'-std=c++11',
		'-Wno-unknown-pragmas',
	]
endif

if target_machine.cpu_family() == 'x86' or target_machine.cpu_family() == 'x86_64'
	cpp_args += ['-DHAVE_INTEL_ATOMIC_PRIMITIVES']
endif

if get_option('use-graphite2')
	src += ['src/hb-graphite2.cc']
	cpp_args += ['-DHAVE_GRAPHITE2', '-DGRAPHITE2_STATIC']
endif

harfbuzz = static_library(
	'harfbuzz',
	src,
	cpp_args : cpp_args,
	include_directories : include_directories('src', '../freetype2/include', '../graphite2/include', '../icu4c/source/common/'),
	pic : true
)

harfbuzz_dep = declare_dependency(
	include_directories : include_directories('src'),
	link_with : harfbuzz
)
