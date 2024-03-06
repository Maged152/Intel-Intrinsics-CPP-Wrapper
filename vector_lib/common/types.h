#pragma once

namespace qlm
{
	enum class Status_t
	{
		VECTOR_SUCCESS,
		SCALAR_SUCCESS
	};

	enum class Compare_t : int
	{
		 CMP_EQ_OQ   = 0,	/* Equal (ordered, non-signaling)  */
		 CMP_LT_OS = 1,	    /* Less-than (ordered, signaling)  */
		 CMP_LE_OS = 2,	    /* Less-than-or-equal (ordered, signaling)  */
		 CMP_UNORD_Q = 3,	/* Unordered (non-signaling)  */
		 CMP_NEQ_UQ = 4,	/* Not-equal (unordered, non-signaling)  */
		 CMP_NLT_US = 5,	/* Not-less-than (unordered, signaling)  */
		 CMP_NLE_US = 6,	/* Not-less-than-or-equal (unordered, signaling)  */
		 CMP_ORD_Q = 7,	    /* Ordered (nonsignaling)   */
		 CMP_EQ_UQ = 8,	    /* Equal (unordered, non-signaling)  */
		 CMP_NGE_US = 9,	/* Not-greater-than-or-equal (unord, signaling)  */
		 CMP_NGT_US = 10,	/* Not-greater-than (unordered, signaling)  */
		 CMP_FALSE_OQ = 11, /* False (ordered, non-signaling)  */
		 CMP_NEQ_OQ = 12,   /* Not-equal (ordered, non-signaling)  */
		 CMP_GE_OS = 13,	/* Greater-than-or-equal (ordered, signaling)  */
		 CMP_GT_OS = 14,	/* Greater-than (ordered, signaling)  */
		 CMP_TRUE_UQ = 15,  /* True (unordered, non-signaling)  */
		 CMP_EQ_OS = 16,	/* Equal (ordered, signaling)  */
		 CMP_LT_OQ = 17,	/* Less-than (ordered, non-signaling)  */
		 CMP_LE_OQ = 18,	/* Less-than-or-equal (ordered, non-signaling)  */
		 CMP_UNORD_S = 19,	/* Unordered (signaling)  */
		 CMP_NEQ_US = 20,	/* Not-equal (unordered, signaling)  */
		 CMP_NLT_UQ = 21,	/* Not-less-than (unordered, non-signaling)  */
		 CMP_NLE_UQ = 22,	/* Not-less-than-or-equal (unord, non-signaling)  */
		 CMP_ORD_S = 23,	/* Ordered (signaling)  */
		 CMP_EQ_US = 24,	/* Equal (unordered, signaling)  */
		 CMP_NGE_UQ = 25,	/* Not-greater-than-or-equal (unord, non-sign)  */
		 CMP_NGT_UQ = 26,	/* Not-greater-than (unordered, non-signaling)  */
		 CMP_FALSE_OS = 27,	/* False (ordered, signaling)  */
		 CMP_NEQ_OS = 28,	/* Not-equal (ordered, signaling)  */
		 CMP_GE_OQ = 29,	/* Greater-than-or-equal (ordered, non-signaling)  */
		 CMP_GT_OQ = 30,	/* Greater-than (ordered, non-signaling)  */
		 CMP_TRUE_US = 31   /* True (unordered, signaling)  */
	};

}