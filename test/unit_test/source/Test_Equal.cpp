#include "test_helper.h"
#include "gtest/gtest.h"
#include "shakhbat_avx.h"

#include <functional>

// Define the test parameters types
struct AVXEqual : ::testing::TestWithParam<std::tuple<
    double, // min value
    double,  // max value
    test::vector_t
    >>
{};


template <class d_t, class vec_t>
void DoTest(const double min_val, const double max_val)
{
    constexpr d_t threshold = 0;

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
    auto scal_Compare = [](d_t in1, d_t in2) { return in1 == in2 ? 0xFFFFFFFF : 0; };
    scal1.Operation(scal2, scal_dst, scal_Compare);

    // load input vector
    vec1.Load(scal1.data);
    vec2.Load(scal2.data);

    // do vector operation
    vec3 = vec1.Equal(vec2);

    // store results
    vec3.Store(vec_dst.data);

    // compare results
    bool res = test::Compare(vec_dst, scal_dst, threshold);

    EXPECT_EQ(res, true);
}

// Define a parameterized test case
TEST_P(AVXEqual, Test_AVXEqual)
{

    // extract the parameters
    auto& [min_val, max_val, vec_t] = GetParam();

    test::PrintParameter(min_val, "min_val");
    test::PrintParameter(max_val, "max_val");
    test::PrintParameter(vec_t, "data type");

    if (vec_t == test::vector_t::AVX_int32)
    {
        DoTest<int32_t, qlm::v8int32_t>(min_val, max_val);
    }
    else if (vec_t == test::vector_t::AVX_uint32)
    {
        DoTest<uint32_t, qlm::v8uint32_t>(min_val, max_val);
    }
    else if (vec_t == test::vector_t::AVX_int64)
    {
        DoTest<int64_t, qlm::v4int64_t>(min_val, max_val);
    }
    else if (vec_t == test::vector_t::AVX_uint64)
    {
        DoTest<uint64_t, qlm::v4uint64_t>(min_val, max_val);
    }
}


// Instantiate the test case with combinations of values
INSTANTIATE_TEST_CASE_P(
    Test_AVXEqual, AVXEqual,
    ::testing::Combine(
        ::testing::Values(0.0,2.0),
        ::testing::Values(10.0, 100.0),
        ::testing::Values(test::vector_t::AVX_int32, test::vector_t::AVX_uint32,
            test::vector_t::AVX_int64, test::vector_t::AVX_uint64)
    ));