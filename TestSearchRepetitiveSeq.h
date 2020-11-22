#pragma once
#include "SearchRepetitiveSeq.h"
#include <assert.h>
#include "ArraySequence.h"
#include <string.h>

void test_PreficsDict(SearchRepetitiveSeq test, pair<std::string, int>* checkPairs)
{
	Dictionary<std::string, int>* testDict(test.GetDict());

	for (int i(0); i < testDict->GetCount() - 1; i++)
		assert(testDict->Get(checkPairs[i].key) == checkPairs[i].element);
}

void test_GetPair(pair<std::string, int> test, std::string checkKey, int checkEl)
{
	assert(test.key == checkKey);
	assert(test.element == checkEl);
}

void test_SearchRepetitiveSeq()
{
	char mas16[16]{ 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd' };
	ArraySequence<char> arr16(mas16, 16);
	Sequence<char>* seq16 = &arr16;
	SearchRepetitiveSeq  rep16_7_8(seq16, 7, 8);
	SearchRepetitiveSeq  rep16_4_5(seq16, 4, 5);

	char mas12[12]{ 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'a', 'a', 'a', 'a' };
	ArraySequence<char> arr12(mas12, 12);
	Sequence<char>* seq12 = &arr12;
	SearchRepetitiveSeq  rep12_4_6(seq12, 4, 6);
	SearchRepetitiveSeq  rep12_5_7(seq12, 5, 7);

	char mas13[13]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm' };
	ArraySequence<char> arr13(mas13, 13);
	Sequence<char>* seq13 = &arr13;
	SearchRepetitiveSeq  rep13_1_3(seq13, 1, 3 );

	pair<std::string, int> p16_7_8[8];
	p16_7_8[0].key = "abcdabc";
	p16_7_8[0].element = 3;
	p16_7_8[1].key = "abcdabcd";
	p16_7_8[1].element = 3;
	p16_7_8[2].key = "bcdabcd";
	p16_7_8[2].element = 3;
	p16_7_8[3].key = "bcdabcda";
	p16_7_8[3].element = 2;
	p16_7_8[4].key = "cdabcda";
	p16_7_8[4].element = 2;
	p16_7_8[5].key = "cdabcdab";
	p16_7_8[5].element = 2;
	p16_7_8[6].key = "dabcdab";
	p16_7_8[6].element = 2;
	p16_7_8[7].key = "dabcdabc";
	p16_7_8[7].element = 2;

	pair<std::string, int> p16_4_5[8];
	p16_4_5[0].key = "abcd";
	p16_4_5[0].element = 4;
	p16_4_5[1].key = "abcda";
	p16_4_5[1].element = 3;
	p16_4_5[2].key = "bcda";
	p16_4_5[2].element = 3;
	p16_4_5[3].key = "bcdab";
	p16_4_5[3].element = 3;
	p16_4_5[4].key = "cdab";
	p16_4_5[4].element = 3;
	p16_4_5[5].key = "cdabc";
	p16_4_5[5].element = 3;
	p16_4_5[6].key = "dabc";
	p16_4_5[6].element = 3;
	p16_4_5[7].key = "dabcd";
	p16_4_5[7].element = 3;

	pair<std::string, int> p12_4_6[23];
	p12_4_6[0].key = "aaaa";
	p12_4_6[0].element = 2;
	p12_4_6[1].key = "aaaab";
	p12_4_6[1].element = 1;
	p12_4_6[2].key = "aaaabb";
	p12_4_6[2].element = 1;
	p12_4_6[3].key = "aaab";
	p12_4_6[3].element = 1;
	p12_4_6[4].key = "aaabb";
	p12_4_6[4].element = 1;
	p12_4_6[5].key = "aaabbb";
	p12_4_6[5].element = 1;
	p12_4_6[6].key = "aabb";
	p12_4_6[6].element = 1;
	p12_4_6[7].key = "aabbb";
	p12_4_6[7].element = 1;
	p12_4_6[8].key = "aabbbb";
	p12_4_6[8].element = 1;
	p12_4_6[9].key = "abbb";
	p12_4_6[9].element = 1;
	p12_4_6[10].key = "abbbb";
	p12_4_6[10].element = 1;
	p12_4_6[11].key = "abbbba";
	p12_4_6[11].element = 1;
	p12_4_6[12].key = "baaa";
	p12_4_6[12].element = 1;
	p12_4_6[13].key = "baaaa";
	p12_4_6[13].element = 1;
	p12_4_6[14].key = "bbaa";
	p12_4_6[14].element = 1;
	p12_4_6[15].key = "bbaaa";
	p12_4_6[15].element = 1;
	p12_4_6[16].key = "bbaaaa";
	p12_4_6[16].element = 1;
	p12_4_6[17].key = "bbba";
	p12_4_6[17].element = 1;
	p12_4_6[18].key = "bbbaa";
	p12_4_6[18].element = 1;
	p12_4_6[19].key = "bbbaaa";
	p12_4_6[19].element = 1;
	p12_4_6[20].key = "bbbb";
	p12_4_6[20].element = 1;
	p12_4_6[21].key = "bbbba";
	p12_4_6[21].element = 1;
	p12_4_6[22].key = "bbbbaa";
	p12_4_6[22].element = 1;

	pair<std::string, int> p12_5_7[21];
	p12_5_7[0].key = "aaaab";
	p12_5_7[0].element = 1;
	p12_5_7[1].key = "aaaabb";
	p12_5_7[1].element = 1;
	p12_5_7[2].key = "aaaabbb";
	p12_5_7[2].element = 1;
	p12_5_7[3].key = "aaabb";
	p12_5_7[3].element = 1;
	p12_5_7[4].key = "aaabbb";
	p12_5_7[4].element = 1;
	p12_5_7[5].key = "aaabbbb";
	p12_5_7[5].element = 1;
	p12_5_7[6].key = "aabbb";
	p12_5_7[6].element = 1;
	p12_5_7[7].key = "aabbbb";
	p12_5_7[7].element = 1;
	p12_5_7[8].key = "aabbbba";
	p12_5_7[8].element = 1;
	p12_5_7[9].key = "abbbb";
	p12_5_7[9].element = 1;
	p12_5_7[10].key = "abbbba";
	p12_5_7[10].element = 1;
	p12_5_7[11].key = "abbbbaa";
	p12_5_7[11].element = 1;
	p12_5_7[12].key = "baaaa";
	p12_5_7[12].element = 1;
	p12_5_7[13].key = "bbaaa";
	p12_5_7[13].element = 1;
	p12_5_7[14].key = "bbaaaa";
	p12_5_7[14].element = 1;
	p12_5_7[15].key = "bbbaa";
	p12_5_7[15].element = 1;
	p12_5_7[16].key = "bbbaaa";
	p12_5_7[16].element = 1;
	p12_5_7[17].key = "bbbaaaa";
	p12_5_7[17].element = 1;
	p12_5_7[18].key = "bbbba";
	p12_5_7[18].element = 1;
	p12_5_7[19].key = "bbbbaa";
	p12_5_7[19].element = 1;
	p12_5_7[20].key = "bbbbaaa";
	p12_5_7[20].element = 1;

	pair<std::string, int> p13_1_3[36];
	p13_1_3[0].key = "a";
	p13_1_3[0].element = 1;
	p13_1_3[1].key = "ab";
	p13_1_3[1].element = 1;
	p13_1_3[2].key = "abc";
	p13_1_3[2].element = 1;
	p13_1_3[3].key = "b";
	p13_1_3[3].element = 1;
	p13_1_3[4].key = "bc";
	p13_1_3[4].element = 1;
	p13_1_3[5].key = "bcd";
	p13_1_3[5].element = 1;
	p13_1_3[6].key = "c";
	p13_1_3[6].element = 1;
	p13_1_3[7].key = "cd";
	p13_1_3[7].element = 1;
	p13_1_3[8].key = "cde";
	p13_1_3[8].element = 1;
	p13_1_3[9].key = "d";
	p13_1_3[9].element = 1;
	p13_1_3[10].key = "de";
	p13_1_3[10].element = 1;
	p13_1_3[11].key = "def";
	p13_1_3[11].element = 1;
	p13_1_3[12].key = "e";
	p13_1_3[12].element = 1;
	p13_1_3[13].key = "ef";
	p13_1_3[13].element = 1;
	p13_1_3[14].key = "efg";
	p13_1_3[14].element = 1;
	p13_1_3[15].key = "f";
	p13_1_3[15].element = 1;
	p13_1_3[16].key = "fg";
	p13_1_3[16].element = 1;
	p13_1_3[17].key = "fgh";
	p13_1_3[17].element = 1;
	p13_1_3[18].key = "g";
	p13_1_3[18].element = 1;
	p13_1_3[19].key = "gh";
	p13_1_3[19].element = 1;
	p13_1_3[20].key = "ghi";
	p13_1_3[20].element = 1;
	p13_1_3[21].key = "h";
	p13_1_3[21].element = 1;
	p13_1_3[22].key = "hi";
	p13_1_3[22].element = 1;
	p13_1_3[23].key = "hij";
	p13_1_3[23].element = 1;
	p13_1_3[24].key = "i";
	p13_1_3[24].element = 1;
	p13_1_3[25].key = "ij";
	p13_1_3[25].element = 1;
	p13_1_3[26].key = "ijk";
	p13_1_3[26].element = 1;
	p13_1_3[27].key = "j";
	p13_1_3[27].element = 1;
	p13_1_3[28].key = "jk";
	p13_1_3[28].element = 1;
	p13_1_3[29].key = "jkl";
	p13_1_3[29].element = 1;
	p13_1_3[30].key = "k";
	p13_1_3[30].element = 1;
	p13_1_3[31].key = "kl";
	p13_1_3[31].element = 1;
	p13_1_3[32].key = "klm";
	p13_1_3[32].element = 1;
	p13_1_3[33].key = "l";
	p13_1_3[33].element = 1;
	p13_1_3[34].key = "lm";
	p13_1_3[34].element = 1;
	p13_1_3[35].key = "m";
	p13_1_3[35].element = 1;

	test_PreficsDict(rep16_7_8, p16_7_8);
	test_PreficsDict(rep16_4_5, p16_4_5);
	test_PreficsDict(rep12_4_6, p12_4_6);
	test_PreficsDict(rep12_5_7, p12_5_7);
	test_PreficsDict(rep13_1_3, p13_1_3);

	test_GetPair(rep16_7_8.GetPair(), "abcdabc", 3);
	test_GetPair(rep16_4_5.GetPair(), "abcd", 4);
	test_GetPair(rep12_4_6.GetPair(), "aaaa", 2);
	test_GetPair(rep12_5_7.GetPair(), "equal numbers", 1);
	test_GetPair(rep13_1_3.GetPair(), "equal numbers", 1);

	//std::cout << "all test work" << std::endl;
}