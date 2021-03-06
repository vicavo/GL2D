#ifndef ___OGL2D_OPENGL_H___
#define ___OGL2D_OPENGL_H___

#if !defined( STATIC_LIB )
#	if defined( GL2D_EXPORTS )
#		define GL2D_API __declspec( dllexport )
#	else
#		define GL2D_API __declspec( dllimport )
#	endif
#else
#	define GL2D_API
#endif

#include <Windows.h>
#include <gl/GL.h>
#include <functional>
#include <cstdint>

#if _MSC_VER > 1700
#	define DEF_HAS_VARIADIC_TEMPLATES	1
#else
#	define DEF_HAS_VARIADIC_TEMPLATES	0
#endif

static const GLuint GL_TEXTURE0 = 0x84C0;

static const GLuint GL_INVALID_INDEX = 0xFFFFFFFF;

typedef enum GL2D_GL_FRAMEBUFFER_STATUS : unsigned int
{	GL2D_GL_FRAMEBUFFER_COMPLETE						= 0x8CD5
,	GL2D_GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT			= 0x8CD6
,	GL2D_GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT	= 0x8CD7
,	GL2D_GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER			= 0x8CDB
,	GL2D_GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER			= 0x8CDC
,	GL2D_GL_FRAMEBUFFER_UNSUPPORTED						= 0x8CDD
,	GL2D_GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE			= 0x8D56
,	GL2D_GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS		= 0x8DA8
}	GL2D_GL_FRAMEBUFFER_STATUS;

typedef enum GL2D_GL_TEXTURE_ATTACHMENT : unsigned int
{	GL2D_GL_TEXTURE_ATTACHMENT_NONE		= 0
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR0	= 0x8CE0
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR1	= 0x8CE1
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR2	= 0x8CE2
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR3	= 0x8CE3
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR4	= 0x8CE4
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR5	= 0x8CE5
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR6	= 0x8CE6
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR7	= 0x8CE7
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR8	= 0x8CE8
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR9	= 0x8CE9
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR10	= 0x8CEA
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR11	= 0x8CEB
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR12	= 0x8CEC
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR13	= 0x8CED
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR14	= 0x8CEE
,	GL2D_GL_TEXTURE_ATTACHMENT_COLOR15	= 0x8CEF
,	GL2D_GL_TEXTURE_ATTACHMENT_DEPTH	= 0x8D00
,	GL2D_GL_TEXTURE_ATTACHMENT_STENCIL	= 0x8D20
}	GL2D_GL_TEXTURE_ATTACHMENT;

typedef enum GL2D_GL_FRAMEBUFFER_MODE : unsigned int
{	GL2D_GL_FRAMEBUFFER_MODE_READ		= 0x8CA8
,	GL2D_GL_FRAMEBUFFER_MODE_DRAW		= 0x8CA9
,	GL2D_GL_FRAMEBUFFER_MODE_DEFAULT	= 0x8D40
}	GL2D_GL_FRAMEBUFFER_MODE;

typedef enum GL2D_GL_RENDERBUFFER_MODE : unsigned int
{	GL2D_GL_RENDERBUFFER_MODE_DEFAULT	= 0x8D41
}	GL2D_GL_RENDERBUFFER_MODE;

typedef enum GL2D_GL_RENDERBUFFER_ATTACHMENT : unsigned int
{	GL2D_GL_RENDERBUFFER_ATTACHMENT_NONE	= 0
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR0	= 0x8CE0
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR1	= 0x8CE1
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR2	= 0x8CE2
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR3	= 0x8CE3
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR4	= 0x8CE4
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR5	= 0x8CE5
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR6	= 0x8CE6
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR7	= 0x8CE7
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR8	= 0x8CE8
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR9	= 0x8CE9
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR10	= 0x8CEA
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR11	= 0x8CEB
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR12	= 0x8CEC
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR13	= 0x8CED
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR14	= 0x8CEE
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_COLOR15	= 0x8CEF
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_DEPTH	= 0x8D00
,	GL2D_GL_RENDERBUFFER_ATTACHMENT_STENCIL	= 0x8D20
}	GL2D_GL_RENDERBUFFER_ATTACHMENT;

typedef enum GL2D_GL_RENDERBUFFER_PARAMETER : unsigned int
{	GL2D_GL_RENDERBUFFER_PARAMETER_WIDTH			= 0x8D42
,	GL2D_GL_RENDERBUFFER_PARAMETER_HEIGHT			= 0x8D43
,	GL2D_GL_RENDERBUFFER_PARAMETER_INTERNAL_FORMAT	= 0x8D44
,	GL2D_GL_RENDERBUFFER_PARAMETER_RED_SIZE			= 0x8D50
,	GL2D_GL_RENDERBUFFER_PARAMETER_GREEN_SIZE		= 0x8D51
,	GL2D_GL_RENDERBUFFER_PARAMETER_BLUE_SIZE		= 0x8D52
,	GL2D_GL_RENDERBUFFER_PARAMETER_ALPHA_SIZE		= 0x8D53
,	GL2D_GL_RENDERBUFFER_PARAMETER_DEPTH_SIZE		= 0x8D54
,	GL2D_GL_RENDERBUFFER_PARAMETER_STENCIL_SIZE		= 0x8D55
}	GL2D_GL_RENDERBUFFER_PARAMETER;

typedef enum GL2D_GL_RENDERBUFFER_STORAGE : unsigned int
{	GL2D_GL_RENDERBUFFER_STORAGE_L8			= 0x8229
,	GL2D_GL_RENDERBUFFER_STORAGE_L16F		= 0x822D
,	GL2D_GL_RENDERBUFFER_STORAGE_L32F		= 0x822E
,	GL2D_GL_RENDERBUFFER_STORAGE_A8L8		= 0x822C
,	GL2D_GL_RENDERBUFFER_STORAGE_AL16F		= 0x822F
,	GL2D_GL_RENDERBUFFER_STORAGE_AL32F		= 0x8230
,	GL2D_GL_RENDERBUFFER_STORAGE_RGB5_A1	= 0x8057
,	GL2D_GL_RENDERBUFFER_STORAGE_RGBA4		= 0x8056
,	GL2D_GL_RENDERBUFFER_STORAGE_RGB565		= 0x8D62
,	GL2D_GL_RENDERBUFFER_STORAGE_RGB8		= 0x8051
,	GL2D_GL_RENDERBUFFER_STORAGE_RGBA8		= 0x8058
,	GL2D_GL_RENDERBUFFER_STORAGE_RGB16F		= 0x881B
,	GL2D_GL_RENDERBUFFER_STORAGE_RGBA16F	= 0x881A
,	GL2D_GL_RENDERBUFFER_STORAGE_RGB32F		= 0x8815
,	GL2D_GL_RENDERBUFFER_STORAGE_RGBA32F	= 0x8814
,	GL2D_GL_RENDERBUFFER_STORAGE_DXTC1		= 0x83F1
,	GL2D_GL_RENDERBUFFER_STORAGE_DXTC3		= 0x83F2
,	GL2D_GL_RENDERBUFFER_STORAGE_DXTC5		= 0x83F3
,	GL2D_GL_RENDERBUFFER_STORAGE_DEPTH16	= 0x81A5
,	GL2D_GL_RENDERBUFFER_STORAGE_DEPTH24	= 0x81A6
,	GL2D_GL_RENDERBUFFER_STORAGE_DEPTH32	= 0x81A7
,	GL2D_GL_RENDERBUFFER_STORAGE_STENCIL1	= 0x8D46
,	GL2D_GL_RENDERBUFFER_STORAGE_STENCIL4	= 0x8D47
,	GL2D_GL_RENDERBUFFER_STORAGE_STENCIL8	= 0x8D48
,	GL2D_GL_RENDERBUFFER_STORAGE_STENCIL16	= 0x8D49
}	GL2D_GL_RENDERBUFFER_STORAGE;

typedef enum GL2D_GL_BUFFER_TARGET : unsigned int
{	GL2D_GL_BUFFER_TARGET_ARRAY					= 0x8892
,	GL2D_GL_BUFFER_TARGET_ELEMENT_ARRAY			= 0x8893
,	GL2D_GL_BUFFER_TARGET_PIXEL_PACK			= 0x88EB
,	GL2D_GL_BUFFER_TARGET_PIXEL_UNPACK			= 0x88EC
,	GL2D_GL_BUFFER_TARGET_UNIFORM				= 0x8A11
,	GL2D_GL_BUFFER_TARGET_TEXTURE				= 0x8C2A
,	GL2D_GL_BUFFER_TARGET_TRANSFORM_FEEDBACK	= 0x8C8E
,	GL2D_GL_BUFFER_TARGET_COPY_READ				= 0x8F36
,	GL2D_GL_BUFFER_TARGET_COPY_WRITE			= 0x8F37
,	GL2D_GL_BUFFER_TARGET_DRAW_INDIRECT			= 0x8F3F
,	GL2D_GL_BUFFER_TARGET_SHADER_STORAGE		= 0x90D2
,	GL2D_GL_BUFFER_TARGET_DISPATCH_INDIRECT		= 0x90EE
,	GL2D_GL_BUFFER_TARGET_QUERY					= 0x9192
,	GL2D_GL_BUFFER_TARGET_ATOMIC_COUNTER		= 0x92C0
}	GL2D_GL_BUFFER_TARGET;

typedef enum GL2D_GL_BUFFER_USAGE
	: GLenum
{	GL2D_GL_BUFFER_USAGE_STREAM_DRAW	= 0x88E0
,	GL2D_GL_BUFFER_USAGE_STREAM_READ	= 0x88E1
,	GL2D_GL_BUFFER_USAGE_STREAM_COPY	= 0x88E2
,	GL2D_GL_BUFFER_USAGE_STATIC_DRAW	= 0x88E4
,	GL2D_GL_BUFFER_USAGE_STATIC_READ	= 0x88E5
,	GL2D_GL_BUFFER_USAGE_STATIC_COPY	= 0x88E6
,	GL2D_GL_BUFFER_USAGE_DYNAMIC_DRAW	= 0x88E8
,	GL2D_GL_BUFFER_USAGE_DYNAMIC_READ	= 0x88E9
,	GL2D_GL_BUFFER_USAGE_DYNAMIC_COPY	= 0x88EA
}	GL2D_GL_BUFFER_USAGE;

typedef enum GL2D_GL_FORMAT : unsigned int
{	GL2D_GL_FORMAT_STENCIL			= 0x1901
,	GL2D_GL_FORMAT_DEPTH			= 0x1902
,	GL2D_GL_FORMAT_RED				= 0x1903
,	GL2D_GL_FORMAT_GREEN			= 0x1904
,	GL2D_GL_FORMAT_BLUE				= 0x1905
,	GL2D_GL_FORMAT_ALPHA			= 0x1906
,	GL2D_GL_FORMAT_RGB				= 0x1907
,	GL2D_GL_FORMAT_RGBA				= 0x1908
,	GL2D_GL_FORMAT_LUMINANCE		= 0x1909
,	GL2D_GL_FORMAT_LUMINANCE_ALPHA	= 0x190A
,	GL2D_GL_FORMAT_BGR				= 0x80E0
,	GL2D_GL_FORMAT_BGRA				= 0x80E1
,	GL2D_GL_FORMAT_RG				= 0x8227
,	GL2D_GL_FORMAT_DEPTH_STENCIL	= 0x84F9
}	GL2D_GL_FORMAT;

typedef enum GL2D_GL_INTERNAL
	: unsigned int
{
	GL2D_GL_INTERNAL_LUMINANCE					= 0x1909,
	GL2D_GL_INTERNAL_ALPHA8						= 0x803C,
	GL2D_GL_INTERNAL_ALPHA16					= 0x803E,
	GL2D_GL_INTERNAL_LUMINANCE8					= 0x8040,
	GL2D_GL_INTERNAL_LUMINANCE16				= 0x8042,
	GL2D_GL_INTERNAL_LUMINANCE8_ALPHA8			= 0x8045,
	GL2D_GL_INTERNAL_LUMINANCE16_ALPHA16		= 0x8048,
	GL2D_GL_INTERNAL_INTENSITY8					= 0x804B,
	GL2D_GL_INTERNAL_INTENSITY16				= 0x804D,
	GL2D_GL_INTERNAL_RGB8						= 0x8051,
	GL2D_GL_INTERNAL_RGB16						= 0x8054,
	GL2D_GL_INTERNAL_RGBA8						= 0x8058,
	GL2D_GL_INTERNAL_RGBA16						= 0x805B,
	GL2D_GL_INTERNAL_DEPTH_COMPONENT16			= 0x81A5,
	GL2D_GL_INTERNAL_DEPTH_COMPONENT24			= 0x81A6,
	GL2D_GL_INTERNAL_DEPTH_COMPONENT32			= 0x81A7,
	GL2D_GL_INTERNAL_R8							= 0x8229,
	GL2D_GL_INTERNAL_RG8						= 0x822B,
	GL2D_GL_INTERNAL_RG16						= 0x822C,
	GL2D_GL_INTERNAL_R16F						= 0x822D,
	GL2D_GL_INTERNAL_R32F						= 0x822E,
	GL2D_GL_INTERNAL_RG16F						= 0x822F,
	GL2D_GL_INTERNAL_RG32F						= 0x8230,
	GL2D_GL_INTERNAL_RGBA32F					= 0x8814,
	GL2D_GL_INTERNAL_RGB32F						= 0x8815,
	GL2D_GL_INTERNAL_RGBA16F					= 0x881A,
	GL2D_GL_INTERNAL_RGB16F						= 0x881B,
	GL2D_GL_INTERNAL_DEPTH24_STENCIL8			= 0x88F0,
	GL2D_GL_INTERNAL_DEPTH_COMPONENT32F			= 0x8CAC,
	GL2D_GL_INTERNAL_STENCIL_INDEX1				= 0x8D46,
	GL2D_GL_INTERNAL_STENCIL_INDEX4				= 0x8D47,
	GL2D_GL_INTERNAL_STENCIL_INDEX8				= 0x8D48,
	GL2D_GL_INTERNAL_STENCIL_INDEX16			= 0x8D49,
}	GL2D_GL_INTERNAL;

typedef enum GL2D_GL_TYPE : unsigned int
{	GL2D_GL_TYPE_DEFAULT						= 0
,	GL2D_GL_TYPE_BYTE							= 0x1400
,	GL2D_GL_TYPE_UNSIGNED_BYTE					= 0x1401
,	GL2D_GL_TYPE_SHORT							= 0x1402
,	GL2D_GL_TYPE_UNSIGNED_SHORT					= 0x1403
,	GL2D_GL_TYPE_INT							= 0x1404
,	GL2D_GL_TYPE_UNSIGNED_INT					= 0x1405
,	GL2D_GL_TYPE_FLOAT							= 0x1406
,	GL2D_GL_TYPE_DOUBLE							= 0x140A
,	GL2D_GL_TYPE_BITMAP							= 0X1A00
,	GL2D_GL_TYPE_UNSIGNED_BYTE_3_3_2			= 0x8032
,	GL2D_GL_TYPE_UNSIGNED_SHORT_4_4_4_4			= 0x8033
,	GL2D_GL_TYPE_UNSIGNED_SHORT_5_5_5_1			= 0x8034
,	GL2D_GL_TYPE_UNSIGNED_INT_8_8_8_8			= 0x8035
,	GL2D_GL_TYPE_UNSIGNED_INT_10_10_10_2		= 0x8036
,	GL2D_GL_TYPE_UNSIGNED_BYTE_2_3_3_REV		= 0x8362
,	GL2D_GL_TYPE_UNSIGNED_SHORT_5_6_5			= 0x8363
,	GL2D_GL_TYPE_UNSIGNED_SHORT_5_6_5_REV		= 0x8364
,	GL2D_GL_TYPE_UNSIGNED_SHORT_4_4_4_4_REV		= 0x8365
,	GL2D_GL_TYPE_UNSIGNED_SHORT_1_5_5_5_REV		= 0x8366
,	GL2D_GL_TYPE_UNSIGNED_INT_8_8_8_8_REV		= 0x8367
,	GL2D_GL_TYPE_UNSIGNED_INT_2_10_10_10_REV	= 0x8368
,	GL2D_GL_TYPE_UNSIGNED_INT_24_8				= 0x84FA
#if CASTOR_USE_DOUBLE
,	GL2D_GL_TYPE_REAL							= GL2D_GL_TYPE_DOUBLE
#else
,	GL2D_GL_TYPE_REAL							= GL2D_GL_TYPE_FLOAT
#endif
}	GL2D_GL_TYPE;

typedef enum GL2D_GL_TEXTURE_INDEX : unsigned int
{	GL2D_GL_TEXTURE_INDEX_0		= 0x84C0
,	GL2D_GL_TEXTURE_INDEX_1		= 0x84C1
,	GL2D_GL_TEXTURE_INDEX_2		= 0x84C2
,	GL2D_GL_TEXTURE_INDEX_3		= 0x84C3
,	GL2D_GL_TEXTURE_INDEX_4		= 0x84C4
,	GL2D_GL_TEXTURE_INDEX_5		= 0x84C5
,	GL2D_GL_TEXTURE_INDEX_6		= 0x84C6
,	GL2D_GL_TEXTURE_INDEX_7		= 0x84C7
,	GL2D_GL_TEXTURE_INDEX_8		= 0x84C8
,	GL2D_GL_TEXTURE_INDEX_9		= 0x84C9
,	GL2D_GL_TEXTURE_INDEX_10	= 0x84CA
,	GL2D_GL_TEXTURE_INDEX_11	= 0x84CB
,	GL2D_GL_TEXTURE_INDEX_12	= 0x84CC
,	GL2D_GL_TEXTURE_INDEX_13	= 0x84CD
,	GL2D_GL_TEXTURE_INDEX_14	= 0x84CE
,	GL2D_GL_TEXTURE_INDEX_15	= 0x84CF
,	GL2D_GL_TEXTURE_INDEX_16	= 0x84D0
,	GL2D_GL_TEXTURE_INDEX_17	= 0x84D1
,	GL2D_GL_TEXTURE_INDEX_18	= 0x84D2
,	GL2D_GL_TEXTURE_INDEX_19	= 0x84D3
,	GL2D_GL_TEXTURE_INDEX_20	= 0x84D4
,	GL2D_GL_TEXTURE_INDEX_21	= 0x84D5
,	GL2D_GL_TEXTURE_INDEX_22	= 0x84D6
,	GL2D_GL_TEXTURE_INDEX_23	= 0x84D7
,	GL2D_GL_TEXTURE_INDEX_24	= 0x84D8
,	GL2D_GL_TEXTURE_INDEX_25	= 0x84D9
,	GL2D_GL_TEXTURE_INDEX_26	= 0x84DA
,	GL2D_GL_TEXTURE_INDEX_27	= 0x84DB
,	GL2D_GL_TEXTURE_INDEX_28	= 0x84DC
,	GL2D_GL_TEXTURE_INDEX_29	= 0x84DD
,	GL2D_GL_TEXTURE_INDEX_30	= 0x84DE
,	GL2D_GL_TEXTURE_INDEX_31	= 0x84DF
}	GL2D_GL_TEXTURE_INDEX;
	
typedef enum GL2D_GL_TEXTURE_MAG_FILTER : unsigned int
{	GL2D_GL_TEXTURE_MAG_FILTER_NEAREST	= 0x2600
,	GL2D_GL_TEXTURE_MAG_FILTER_LINEAR	= 0x2601
};
	
typedef enum GL2D_GL_TEXTURE_MIN_FILTER : unsigned int
{	GL2D_GL_TEXTURE_MIN_FILTER_NEAREST					= 0x2600
,	GL2D_GL_TEXTURE_MIN_FILTER_LINEAR					= 0x2601
,	GL2D_GL_TEXTURE_MIN_FILTER_NEAREST_MIPMAP_NEAREST	= 0x2700
,	GL2D_GL_TEXTURE_MIN_FILTER_LINEAR_MIPMAP_NEAREST	= 0x2701
,	GL2D_GL_TEXTURE_MIN_FILTER_NEAREST_MIPMAP_LINEAR	= 0x2702
,	GL2D_GL_TEXTURE_MIN_FILTER_LINEAR_MIPMAP_LINEAR		= 0x2703
}	GL2D_GL_TEXTURE_MIN_FILTER;
	
typedef enum GL2D_GL_TEXTURE_FILTER : unsigned int
{	GL2D_GL_TEXTURE_FILTER_NEAREST	= 0x2600
,	GL2D_GL_TEXTURE_FILTER_LINEAR	= 0x2601
}	GL2D_GL_TEXTURE_FILTER;

	
typedef enum GL2D_GL_MAX : unsigned int
{
	GL2D_GL_MAX_LIST_NESTING								= 0x0B31,
	GL2D_GL_MAX_EVAL_ORDER									= 0x0D30,
	GL2D_GL_MAX_LIGHTS										= 0x0D31,
	GL2D_GL_MAX_CLIP_PLANES									= 0x0D32,
	GL2D_GL_MAX_TEXTURE_SIZE								= 0x0D33,
	GL2D_GL_MAX_PIXEL_MAP_TABLE								= 0x0D34,
	GL2D_GL_MAX_ATTRIB_STACK_DEPTH							= 0x0D35,
	GL2D_GL_MAX_MODELVIEW_STACK_DEPTH						= 0x0D36,
	GL2D_GL_MAX_NAME_STACK_DEPTH							= 0x0D37,
	GL2D_GL_MAX_PROJECTION_STACK_DEPTH						= 0x0D38,
	GL2D_GL_MAX_TEXTURE_STACK_DEPTH							= 0x0D39,
	GL2D_GL_MAX_VIEWPORT_DIMS								= 0x0D3A,
	GL2D_GL_MAX_CLIENT_ATTRIB_STACK_DEPTH					= 0x0D3B,
	GL2D_GL_MAX_CLIP_DISTANCES								= GL2D_GL_MAX_CLIP_PLANES,
	GL2D_GL_MAX_3D_TEXTURE_SIZE								= 0x8073,
	GL2D_GL_MAX_ELEMENTS_VERTICES							= 0x80E8,
	GL2D_GL_MAX_ELEMENTS_INDICES							= 0x80E9,
	GL2D_GL_MAX_VIEWPORTS									= 0x825B,
	GL2D_GL_MAX_COMPUTE_SHARED_MEMORY_SIZE					= 0x8262,
	GL2D_GL_MAX_COMPUTE_UNIFORM_COMPONENTS					= 0x8263,
	GL2D_GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS				= 0x8264,
	GL2D_GL_MAX_COMPUTE_ATOMIC_COUNTERS						= 0x8265,
	GL2D_GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS			= 0x8266,
	GL2D_GL_MAX_DEBUG_GROUP_STACK_DEPTH						= 0x826C,
	GL2D_GL_MAX_UNIFORM_LOCATIONS							= 0x826E,
	GL2D_GL_MAX_LABEL_LENGTH								= 0x82E8,
	GL2D_GL_MAX_TEXTURE_UNITS								= 0x84E2,
	GL2D_GL_MAX_RENDERBUFFER_SIZE							= 0x84E8,
	GL2D_GL_MAX_RECTANGLE_TEXTURE_SIZE						= 0x84F8,
	GL2D_GL_MAX_TEXTURE_LOD_BIAS							= 0x84FD,
	GL2D_GL_MAX_CUBE_MAP_TEXTURE_SIZE						= 0x851C,
	GL2D_GL_MAX_DRAW_BUFFERS								= 0x8824,
	GL2D_GL_MAX_VERTEX_ATTRIBS								= 0x8869,
	GL2D_GL_MAX_TEXTURE_COORDS								= 0x8871,
	GL2D_GL_MAX_TEXTURE_IMAGE_UNITS							= 0x8872,
	GL2D_GL_MAX_DUAL_SOURCE_DRAW_BUFFERS					= 0x88FC,
	GL2D_GL_MAX_ARRAY_TEXTURE_LAYERS						= 0x88FF,
	GL2D_GL_MAX_PROGRAM_TEXEL_OFFSET						= 0x8905,
	GL2D_GL_MAX_VERTEX_UNIFORM_BLOCKS						= 0x8A2B,
	GL2D_GL_MAX_GEOMETRY_UNIFORM_BLOCKS						= 0x8A2C,
	GL2D_GL_MAX_FRAGMENT_UNIFORM_BLOCKS						= 0x8A2D,
	GL2D_GL_MAX_COMBINED_UNIFORM_BLOCKS						= 0x8A2E,
	GL2D_GL_MAX_UNIFORM_BUFFER_BINDINGS						= 0x8A2F,
	GL2D_GL_MAX_UNIFORM_BLOCK_SIZE							= 0x8A30,
	GL2D_GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS			= 0x8A31,
	GL2D_GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS		= 0x8A32,
	GL2D_GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS		= 0x8A33,
	GL2D_GL_MAX_FRAGMENT_UNIFORM_COMPONENTS					= 0x8B49,
	GL2D_GL_MAX_VERTEX_UNIFORM_COMPONENTS					= 0x8B4A,
	GL2D_GL_MAX_VARYING_FLOATS								= 0x8B4B,
	GL2D_GL_MAX_VARYING_COMPONENTS							= GL2D_GL_MAX_VARYING_FLOATS,
	GL2D_GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS					= 0x8B4C,
	GL2D_GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS				= 0x8B4D,
	GL2D_GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS				= 0x8C29,
	GL2D_GL_MAX_TEXTURE_BUFFER_SIZE							= 0x8C2B,
	GL2D_GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS		= 0x8C80,
	GL2D_GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS	= 0x8C8A,
	GL2D_GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS			= 0x8C8B,
	GL2D_GL_MAX_COLOR_ATTACHMENTS							= 0x8CDF,
	GL2D_GL_MAX_SAMPLES										= 0x8D57,
	GL2D_GL_MAX_GEOMETRY_UNIFORM_COMPONENTS					= 0x8DDF,
	GL2D_GL_MAX_GEOMETRY_OUTPUT_VERTICES					= 0x8DE0,
	GL2D_GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS			= 0x8DE1,
	GL2D_GL_MAX_VERTEX_UNIFORM_VECTORS						= 0x8DFB,
	GL2D_GL_MAX_VARYING_VECTORS								= 0x8DFC,
	GL2D_GL_MAX_FRAGMENT_UNIFORM_VECTORS					= 0x8DFD,
	GL2D_GL_MAX_SAMPLE_MASK_WORDS							= 0x8E59,
	GL2D_GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES			= 0x8F39,
	GL2D_GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS				= 0x90D6,
	GL2D_GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS				= 0x90D7,
	GL2D_GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS			= 0x90D8,
	GL2D_GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS		= 0x90D9,
	GL2D_GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS				= 0x90DA,
	GL2D_GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS				= 0x90DB,
	GL2D_GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS				= 0x90DC,
	GL2D_GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS				= 0x90DD,
	GL2D_GL_MAX_SHADER_STORAGE_BLOCK_SIZE					= 0x90DE,
	GL2D_GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS				= 0x90EB,
	GL2D_GL_MAX_COLOR_TEXTURE_SAMPLES						= 0x910E,
	GL2D_GL_MAX_DEPTH_TEXTURE_SAMPLES						= 0x910F,
	GL2D_GL_MAX_INTEGER_SAMPLES								= 0x9110,
	GL2D_GL_MAX_SERVER_WAIT_TIMEOUT							= 0x9111,
	GL2D_GL_MAX_VERTEX_OUTPUT_COMPONENTS					= 0x9122,
	GL2D_GL_MAX_GEOMETRY_INPUT_COMPONENTS					= 0x9123,
	GL2D_GL_MAX_GEOMETRY_OUTPUT_COMPONENTS					= 0x9124,
	GL2D_GL_MAX_FRAGMENT_INPUT_COMPONENTS					= 0x9125,
	GL2D_GL_MAX_DEBUG_MESSAGE_LENGTH						= 0x9143,
	GL2D_GL_MAX_DEBUG_LOGGED_MESSAGES						= 0x9144,
	GL2D_GL_MAX_COMPUTE_UNIFORM_BLOCKS						= 0x91BB,
	GL2D_GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS					= 0x91BC,
	GL2D_GL_MAX_COMPUTE_IMAGE_UNIFORMS						= 0x91BD,
	GL2D_GL_MAX_COMPUTE_WORK_GROUP_COUNT					= 0x91BE,
	GL2D_GL_MAX_COMPUTE_WORK_GROUP_SIZE						= 0x91BF,
	GL2D_GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS				= 0x92CC,
	GL2D_GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS			= 0x92CD,
	GL2D_GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS		= 0x92CE,
	GL2D_GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS				= 0x92CF,
	GL2D_GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS				= 0x92D0,
	GL2D_GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS				= 0x92D1,
	GL2D_GL_MAX_VERTEX_ATOMIC_COUNTERS						= 0x92D2,
	GL2D_GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS				= 0x92D3,
	GL2D_GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS				= 0x92D4,
	GL2D_GL_MAX_GEOMETRY_ATOMIC_COUNTERS					= 0x92D5,
	GL2D_GL_MAX_FRAGMENT_ATOMIC_COUNTERS					= 0x92D6,
	GL2D_GL_MAX_COMBINED_ATOMIC_COUNTERS					= 0x92D7,
	GL2D_GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE					= 0x92D8,
	GL2D_GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS				= 0x92DC,
	GL2D_GL_MAX_FRAMEBUFFER_WIDTH							= 0x9315,
	GL2D_GL_MAX_FRAMEBUFFER_HEIGHT							= 0x9316,
	GL2D_GL_MAX_FRAMEBUFFER_LAYERS							= 0x9317,
	GL2D_GL_MAX_FRAMEBUFFER_SAMPLES							= 0x9318,
}	GL2D_GL_MAX;

typedef enum GL2D_GL_SHADER_TYPE
	: GLenum
{	GL2D_GL_SHADER_TYPE_VERTEX		= 0x8B31
,	GL2D_GL_SHADER_TYPE_FRAGMENT	= 0x8B30
}	GL2D_GL_SHADER_TYPE;

typedef enum GL2D_GL_SHADER_QUERY
	: GLenum
{	GL2D_GL_SHADER_QUERY_TYPE				= 0x8B4F
,	GL2D_GL_SHADER_QUERY_DELETE_STATUS		= 0x8B80
,	GL2D_GL_SHADER_QUERY_COMPILE_STATUS		= 0x8B81
,	GL2D_GL_SHADER_QUERY_INFO_LOG_LENGTH	= 0x8B84
,	GL2D_GL_SHADER_QUERY_SOURCE_LENGTH		= 0x8B88
}	GL2D_GL_SHADER_QUERY;

typedef enum GL2D_GL_PROGRAM_QUERY
	: GLenum
{	GL2D_GL_PROGRAM_QUERY_DELETE_STATUS					= 0x8B80
,	GL2D_GL_PROGRAM_QUERY_LINK_STATUS					= 0x8B82
,	GL2D_GL_PROGRAM_QUERY_VALIDATE_STATUS				= 0x8B83
,	GL2D_GL_PROGRAM_QUERY_INFO_LOG_LENGTH				= 0x8B84
,	GL2D_GL_PROGRAM_QUERY_ATTACHED_SHADERS				= 0x8B85
,	GL2D_GL_PROGRAM_QUERY_ACTIVE_UNIFORMS				= 0x8B86
,	GL2D_GL_PROGRAM_QUERY_ACTIVE_UNIFORM_MAX_LENGTH		= 0x8B87
,	GL2D_GL_PROGRAM_QUERY_ACTIVE_ATTRIBUTES				= 0x8B89
,	GL2D_GL_PROGRAM_QUERY_ACTIVE_ATTRIBUTE_MAX_LENGTH	= 0x8B8A
}	GL2D_GL_PROGRAM_QUERY;

#endif
