#ifndef _CPP_SHARED_H_
#define _CPP_SHARED_H_

#include <regex>

enum struct array2d_type : int
{
    UInt8 = 0,
    UInt16,
    UInt32,
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    RgbPixel,
    RgbAlphaPixel,
    HsiPixel,
    Matrix,
};

enum struct matrix_element_type : int
{
    UInt8 = 0,
    UInt16,
    UInt32,
    UInt64,
    Int8,
    Int16,
    Int32,
    Int64,
    Float,
    Double,
    RgbPixel,
    RgbAlphaPixel,
    HsiPixel
};

enum struct vector_element_type : int
{
    UInt8 = 0,
    UInt16,
    UInt32,
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

enum struct numeric_type : int
{
    UInt8 = 0,
    UInt16,
    UInt32,
    UInt64,
    Int8,
    Int16,
    Int32,
    Int64,
    Float,
    Double
};

enum element_type : int
{

    OpHeatmap = 0,

    OpJet,

    OpArray2dToMat,

    OpTrans,

    OpStdVectToMat,

    OpJoinRows

};

enum struct interpolation_type : int
{

    NearestNeighbor = 0,

    Bilinear,

    Quadratic

};

enum struct point_mapping_type : int
{

    Rotator = 0,

    Transform,

    TransformAffine,

    TransformProjective

};

enum struct mlp_kernel_type : int
{

    Kernel1 = 0 // mlp_kernel_1

};

enum struct running_stats_type : int
{

    Float = 0,

    Double

};

enum struct pyramid_type : int
{

    Down = 0

};

enum struct fhog_feature_extractor_type : int
{

    Default = 0

};

enum struct image_pixel_format_type : int
{

    Bgr = 0,

    Bgra,

    Rgb,

    Rgba,

};

enum struct log_level : int
{

    All = 0,

    Trace,

    Debug,

    Info,

    Warn,

    Error,

    Fatal,

    None

};

enum struct kernel_type : int
{

    HistogramIntersection,

    Linear,

    Offset,

    Polynomial,

    RadialBasis,

    Sigmoid

};

typedef struct
{
    // uint8_t
    uint8_t uint8_t_start;
    uint8_t uint8_t_inc;
    uint8_t uint8_t_end;
    bool use_uint8_t_inc;

    // uint16_t
    uint16_t uint16_t_start;
    uint16_t uint16_t_inc;
    uint16_t uint16_t_end;
    bool use_uint16_t_inc;

    // int8_t
    int8_t int8_t_start;
    int8_t int8_t_inc;
    int8_t int8_t_end;
    bool use_int8_t_inc;

    // int16_t
    int16_t int16_t_start;
    int16_t int16_t_inc;
    int16_t int16_t_end;
    bool use_int16_t_inc;

    // int32_t
    int32_t int32_t_start;
    int32_t int32_t_inc;
    int32_t int32_t_end;
    bool use_int32_t_inc;

    // float
    float float_start;
    float float_inc;
    float float_end;
    bool use_float_inc;

    // double
    double double_start;
    double double_inc;
    double double_end;
    bool use_double_inc;

    bool use_num;
    int num;
} matrix_range_exp_create_param;

#define ERR_OK                                                            0x00000000

// General
#define ERR_GENERAL_ERROR                                                 0x76000000
#define ERR_GENERAL_FILE_IO                         -(ERR_GENERAL_ERROR | 0x00000001)
#define ERR_GENERAL_IMAGE_LOAD                      -(ERR_GENERAL_ERROR | 0x00000002)
#define ERR_GENERAL_SERIALIZATION                   -(ERR_GENERAL_ERROR | 0x00000003)

// CUDA
#define ERR_CUDA_ERROR                                                    0x77000000
#define ERR_CUDA_OUT_OF_MEMORY                         -(ERR_CUDA_ERROR | 0x00000001)

// statistics/statistics.h
#define ERR_RUNNING_STATS_ERROR                                           0x78000000
#define ERR_RUNNING_STATS_TYPE_NOT_SUPPORT    -(ERR_RUNNING_STATS_ERROR | 0x00000001)

// vector
#define ERR_VECTOR_ERROR                                                  0x79000000
#define ERR_VECTOR_TYPE_NOT_SUPPORT                  -(ERR_VECTOR_ERROR | 0x00000001)

// mlp
#define ERR_MLP_ERROR                                                     0x7A000000
#define ERR_MLP_KERNEL_NOT_SUPPORT                      -(ERR_MLP_ERROR | 0x00000001)

// array2d
#define ERR_ARRAY2D_ERROR                                                 0x7B000000
#define ERR_ARRAY2D_TYPE_NOT_SUPPORT                -(ERR_ARRAY2D_ERROR | 0x00000001)

// matrix
#define ERR_MATRIX_ERROR                                                  0x7C000000
#define ERR_MATRIX_ELEMENT_TYPE_NOT_SUPPORT          -(ERR_MATRIX_ERROR | 0x00000001)
#define ERR_MATRIX_ELEMENT_TEMPLATE_SIZE_NOT_SUPPORT -(ERR_MATRIX_ERROR | 0x00000002)
#define ERR_MATRIX_OP_TYPE_NOT_SUPPORT               -(ERR_MATRIX_ERROR | 0x00000003)

// fhog
#define ERR_FHOG_ERROR                                                    0x7D000000
#define ERR_FHOG_NOT_SUPPORT_EXTRACTOR                 -(ERR_FHOG_ERROR | 0x00000001)

// pyramid
#define ERR_PYRAMID_ERROR                                                 0x7E000000
#define ERR_PYRAMID_NOT_SUPPORT_RATE                -(ERR_PYRAMID_ERROR | 0x00000001)
#define ERR_PYRAMID_NOT_SUPPORT_TYPE                -(ERR_PYRAMID_ERROR | 0x00000002)

// Dnn
#define ERR_DNN_ERROR                                                     0x7F000000
#define ERR_DNN_NOT_SUPPORT_NETWORKTYPE                 -(ERR_DNN_ERROR | 0x00000001)
#define ERR_DNN_PROPAGATE_EXCEPTION                     -(ERR_DNN_ERROR | 0x00000002)
#define ERR_DNN_NOT_CLONEABLE_AS_SPECIFIED_NETWORKTYPE  -(ERR_DNN_ERROR | 0x00000003)

#pragma region macro

#define ELEMENT_TYPE element
#undef ELEMENT_TYPE

#pragma region CUDA

// Ex.
// Error while calling cudaGetDevice(&the_device_id) in file d:\works\lib\dlib\19.15\dlib\cuda\gpu_data.cpp:178. code: 35, reason: CUDA driver version is insufficient for CUDA runtime version
#define cuda_error_to_error_code(cuda_error, error) \
do {\
    error = ERR_CUDA_ERROR;\
    std::cmatch results;\
    if (std::regex_search(cuda_error.info.c_str(), results, std::regex(".+code: (\\d+), reason: .*")))\
    {\
        if (results.size() == 2)\
        {\
            auto code = results[1].str();\
            auto icode = std::stoi(code);\
            error = ERR_CUDA_ERROR + icode;\
        }\
    }\
    error = -error;\
} while (0)

#pragma endregion CUDA

#define array_copy(__TYPE__, src, dst)\
do {\
    dlib::array<array2d<__TYPE__>*>* tmp = static_cast<dlib::array<array2d<__TYPE__>*>*>(dst);\
    for (int index = 0; index < src.size(); index++)\
    {\
        /* dlib::array2d deleted copy constructor :( */ \
        array2d<__TYPE__>& a = src[index];\
        array2d<__TYPE__>* cpy = new array2d<__TYPE__>(a.nr(), a.nc());\
        array2d<__TYPE__>& ref = *cpy;\
        for (int r = 0; r < a.nr(); r++)\
            for (int c = 0; c < a.nc(); c++)\
                ref[r][c] = a[r][c];\
\
        tmp->push_back(cpy);\
    }\
} while (0)

#define array_copy2(__TYPE__, src, dst)\
do {\
    dlib::array<array2d<__TYPE__>>* tmp = static_cast<dlib::array<array2d<__TYPE__>>*>(dst);\
    for (int index = 0; index < src.size(); index++)\
    {\
        /* dlib::array2d deleted copy constructor :( */ \
        array2d<__TYPE__>& a = src[index];\
        array2d<__TYPE__> cpy(a.nr(), a.nc());\
        array2d<__TYPE__>& ref = cpy;\
        for (int r = 0; r < a.nr(); r++)\
            for (int c = 0; c < a.nc(); c++)\
                ref[r][c] = a[r][c];\
\
        tmp->push_back(cpy);\
    }\
} while (0)

#define vector_pointer_to_value(__TYPE__, src, dst) \
do {\
    std::vector<__TYPE__*>& tmp_src = *static_cast<std::vector<__TYPE__*>*>(src);\
    for (int index = 0; index < tmp_src.size(); index++)\
    {\
        __TYPE__& tmp = *tmp_src.at(index);\
        dst.push_back(tmp);\
    }\
} while (0)

#define vector_vector_pointer_to_value(__TYPE__, src, dst) \
do {\
    std::vector<std::vector<__TYPE__*>*>& tmp_src = *static_cast<std::vector<std::vector<__TYPE__*>*>*>(src);\
    for (int j = 0 ; j < tmp_src.size(); j++)\
    {\
        auto tmpVector = tmp_src.at(j);\
        std::vector<__TYPE__> vector;\
        for (int i = 0 ; i < tmpVector->size(); i++)\
        {\
            __TYPE__& o = *(tmpVector->at(i));\
            vector.push_back(o);\
        }\
        dst.push_back(vector);\
    }\
} while (0)

#define vector_vector_valueType_to_value(__TYPE__, src, dst) \
do {\
    std::vector<std::vector<__TYPE__>*>& tmp_src = *static_cast<std::vector<std::vector<__TYPE__>*>*>(src);\
    for (int j = 0 ; j < tmp_src.size(); j++)\
    {\
        auto tmpVector = tmp_src.at(j);\
        std::vector<__TYPE__> vector;\
        for (int i = 0 ; i < tmpVector->size(); i++)\
        {\
            __TYPE__ o = tmpVector->at(i);\
            vector.push_back(o);\
        }\
        dst.push_back(vector);\
    }\
} while (0)

#define new_instance_vector_to_instance(__TYPE__, src, dst) \
do {\
    std::vector<__TYPE__*>& tmp_src = *static_cast<std::vector<__TYPE__*>*>(src);\
    for (int index = 0; index < tmp_src.size(); index++)\
    {\
        __TYPE__& tmp = *tmp_src[index];\
        dst.push_back(tmp);\
    }\
} while (0)

#define vector_to_new_instance(__TYPE__, src, dst) \
do {\
    for (int index = 0; index < src.size(); index++)\
    {\
        __TYPE__& tmp = src[index];\
        dst->push_back(new __TYPE__(tmp));\
    }\
} while (0)

#pragma endregion template

#pragma region matrix_template_size

#pragma region general

#define matrix_template_size_arg1_template(__TYPE__, __ROWS__, __COLUMNS__, __FUNC__, error, arg1) \
do {\
    if (__ROWS__ == 0 && __COLUMNS__ == 0)\
    {\
        __FUNC__(__TYPE__, 0, 0, error, arg1);\
    }\
    else if (__ROWS__ == 0 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 0, 1, error, arg1);\
    }\
    else if (__ROWS__ == 1 && __COLUMNS__ == 3)\
    {\
        __FUNC__(__TYPE__, 1, 3, error, arg1);\
    }\
    else if (__ROWS__ == 2 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 2, 1, error, arg1);\
    }\
    else if (__ROWS__ == 5 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 5, 1, error, arg1);\
    }\
    else if (__ROWS__ == 31 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 31, 1, error, arg1);\
    }\
    else\
    {\
        error = ERR_MATRIX_ELEMENT_TEMPLATE_SIZE_NOT_SUPPORT;\
    }\
} while (0)

#define matrix_template_size_arg2_template(__TYPE__, __ROWS__, __COLUMNS__, __FUNC__, error, arg1, arg2) \
do {\
    if (__ROWS__ == 0 && __COLUMNS__ == 0)\
    {\
        __FUNC__(__TYPE__, 0, 0, error, arg1, arg2);\
    }\
    else if (__ROWS__ == 0 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 0, 1, error, arg1, arg2);\
    }\
    else if (__ROWS__ == 1 && __COLUMNS__ == 3)\
    {\
        __FUNC__(__TYPE__, 1, 3, error, arg1, arg2);\
    }\
    else if (__ROWS__ == 2 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 2, 1, error, arg1, arg2);\
    }\
    else if (__ROWS__ == 5 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 5, 1, error, arg1, arg2);\
    }\
    else if (__ROWS__ == 31 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 31, 1, error, arg1, arg2);\
    }\
    else\
    {\
        error = ERR_MATRIX_ELEMENT_TEMPLATE_SIZE_NOT_SUPPORT;\
    }\
} while (0)

#define matrix_template_size_arg3_template(__TYPE__, __ROWS__, __COLUMNS__, __FUNC__, error, arg1, arg2, arg3) \
do {\
    if (__ROWS__ == 0 && __COLUMNS__ == 0)\
    {\
        __FUNC__(__TYPE__, 0, 0, error, arg1, arg2, arg3);\
    }\
    else if (__ROWS__ == 0 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 0, 1, error, arg1, arg2, arg3);\
    }\
    else if (__ROWS__ == 1 && __COLUMNS__ == 3)\
    {\
        __FUNC__(__TYPE__, 1, 3, error, arg1, arg2, arg3);\
    }\
    else if (__ROWS__ == 2 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 2, 1, error, arg1, arg2, arg3);\
    }\
    else if (__ROWS__ == 5 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 5, 1, error, arg1, arg2, arg3);\
    }\
    else if (__ROWS__ == 31 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 31, 1, error, arg1, arg2, arg3);\
    }\
    else\
    {\
        error = ERR_MATRIX_ELEMENT_TEMPLATE_SIZE_NOT_SUPPORT;\
    }\
} while (0)

#define matrix_template_size_arg4_template(__TYPE__, __ROWS__, __COLUMNS__, __FUNC__, error, arg1, arg2, arg3, arg4) \
do {\
    if (__ROWS__ == 0 && __COLUMNS__ == 0)\
    {\
        __FUNC__(__TYPE__, 0, 0, error, arg1, arg2, arg3, arg4);\
    }\
    else if (__ROWS__ == 0 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 0, 1, error, arg1, arg2, arg3, arg4);\
    }\
    else if (__ROWS__ == 1 && __COLUMNS__ == 3)\
    {\
        __FUNC__(__TYPE__, 1, 3, error, arg1, arg2, arg3, arg4);\
    }\
    else if (__ROWS__ == 2 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 2, 1, error, arg1, arg2, arg3, arg4);\
    }\
    else if (__ROWS__ == 5 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 5, 1, error, arg1, arg2, arg3, arg4);\
    }\
    else if (__ROWS__ == 31 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 31, 1, error, arg1, arg2, arg3, arg4);\
    }\
    else\
    {\
        error = ERR_MATRIX_ELEMENT_TEMPLATE_SIZE_NOT_SUPPORT;\
    }\
} while (0)

#define matrix_template_size_arg5_template(__TYPE__, __ROWS__, __COLUMNS__, __FUNC__, error, arg1, arg2, arg3, arg4, arg5) \
do {\
    if (__ROWS__ == 0 && __COLUMNS__ == 0)\
    {\
        __FUNC__(__TYPE__, 0, 0, error, arg1, arg2, arg3, arg4, arg5);\
    }\
    else if (__ROWS__ == 0 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 0, 1, error, arg1, arg2, arg3, arg4, arg5);\
    }\
    else if (__ROWS__ == 1 && __COLUMNS__ == 3)\
    {\
        __FUNC__(__TYPE__, 1, 3, error, arg1, arg2, arg3, arg4, arg5);\
    }\
    else if (__ROWS__ == 2 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 2, 1, error, arg1, arg2, arg3, arg4, arg5);\
    }\
    else if (__ROWS__ == 5 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 5, 1, error, arg1, arg2, arg3, arg4, arg5);\
    }\
    else if (__ROWS__ == 31 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 31, 1, error, arg1, arg2, arg3, arg4, arg5);\
    }\
    else\
    {\
        error = ERR_MATRIX_ELEMENT_TEMPLATE_SIZE_NOT_SUPPORT;\
    }\
} while (0)

#pragma endregion general

#pragma region a column vector

#define matrix_template_size_one_column_vector_arg1_template(__TYPE__, __ROWS__, __COLUMNS__, __FUNC__, error, arg1) \
do {\
    if (__ROWS__ == 0 && __COLUMNS__ == 0)\
    {\
        __FUNC__(__TYPE__, 0, 0, error, arg1);\
    }\
    else if (__ROWS__ == 0 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 0, 1, error, arg1);\
    }\
    else if (__ROWS__ == 5 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 5, 1, error, arg1);\
    }\
    else if (__ROWS__ == 31 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 31, 1, error, arg1);\
    }\
    else\
    {\
        error = ERR_MATRIX_ELEMENT_TEMPLATE_SIZE_NOT_SUPPORT;\
    }\
} while (0)

#define matrix_template_size_one_column_vector_arg5_template(__TYPE__, __ROWS__, __COLUMNS__, __FUNC__, error, arg1, arg2, arg3, arg4, arg5) \
do {\
    if (__ROWS__ == 0 && __COLUMNS__ == 0)\
    {\
        __FUNC__(__TYPE__, 0, 0, error, arg1, arg2, arg3, arg4, arg5);\
    }\
    else if (__ROWS__ == 0 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 0, 1, error, arg1, arg2, arg3, arg4, arg5);\
    }\
    else if (__ROWS__ == 5 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 5, 1, error, arg1, arg2, arg3, arg4, arg5);\
    }\
    else if (__ROWS__ == 31 && __COLUMNS__ == 1)\
    {\
        __FUNC__(__TYPE__, 31, 1, error, arg1, arg2, arg3, arg4, arg5);\
    }\
    else\
    {\
        error = ERR_MATRIX_ELEMENT_TEMPLATE_SIZE_NOT_SUPPORT;\
    }\
} while (0)

#pragma endregion a column vector

#pragma endregion matrix_template_size

#pragma endregion macro

#endif