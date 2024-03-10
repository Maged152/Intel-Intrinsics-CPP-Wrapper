#include "test_helper.h"
#include "gtest/gtest.h"
#include "shakhbat_avx.h"
#include <functional>

// Define the test parameters types
struct AVXAnd : ::testing::TestWithParam<std::tuple<
    double, // min value
    double,  // max value
    test::vector_t
    >>
{};


template <class d_t, class vec_t>
void DoTest(const double min_val, const double max_val)
{
    constexpr float threshold = 0.0f;

    // vector objects
    vec_t vec1{};
    vec_t vec2{};
    vec_t vec3{};

    // scalar objects
    test::Array<d_t> scal1{ vec1.Length() };
    test::Array<d_t> scal2{ vec1.Length() };
    test::Array<d_t> scal_dst{ vec1.Length() };
    test::Array<d_t> vec_dst{ vec1.Length() };

    // random initialization
    scal1.RandomInit(min_val, max_val);
    scal2.RandomInit(min_val, max_val);

    // do scalar operation
    auto scal_And = [](d_t in1, d_t in2) 
    { 
        d_t out;
        if constexpr (std::is_same_v<d_t, float>)
        {
            int32_t* int_in1 = reinterpret_cast<int32_t*>(&in1);
            int32_t* int_in2 = reinterpret_cast<int32_t*>(&in2);
            int32_t* int_out = reinterpret_cast<int32_t*>(&out);
            *int_out = *int_in1 & *int_in2;
        }
        
        return out;
    };
    scal1.Operation(scal2, scal_dst, scal_And);

    // load input vector
    vec1.Load(scal1.data);
    vec2.Load(scal2.data);

    // do vector operation
    vec3 = vec1.And(vec2);

    // store results
    vec3.Store(vec_dst.data);

    // compare results
    bool res = test::Compare(vec_dst, scal_dst, threshold);

    EXPECT_EQ(res, true);
}

// Define a parameterized test case
TEST_P(AVXAnd, Test_AVXAdd)
{

    // extract the parameters
    auto& [min_val, max_val, vec_t] = GetParam();

    test::PrintParameter(min_val, "min_val");
    test::PrintParameter(max_val, "max_val");
    test::PrintParameter(vec_t, "data type");

    if (vec_t == test::vector_t::AVX_float)
    {
        DoTest<float, qlm::v8float_t>(min_val, max_val);
    }
    else if (vec_t == test::vector_t::AVX_double)
    {
        DoTest<double, qlm::v4double_t>(min_val, max_val);
    }
}


// Instantiate the test case with combinations of values
INSTANTIATE_TEST_CASE_P(
    Test_AVXAdd, AVXAnd,
    ::testing::Combine(
        ::testing::Values(0.0, -100.0),
        ::testing::Values(1.0, 100.0),
        ::testing::Values(test::vector_t::AVX_float, test::vector_t::AVX_double)
    ));