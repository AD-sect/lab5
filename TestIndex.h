#pragma once
#include "index.h"
#include <assert.h>

inline void test26( Dictionary<std::string, int>* dict, Index<int> testDict, std::string str)
{
	int i(0);
	std::string s = "";
	while (i < str.length())
	{
		s = str.substr(i, 1);
		assert(dict->Get(s) == testDict.GetDict()->Get(s));
		//std::cout << s << std::endl;
		i += 2;
	}
}

inline void test8(Dictionary<std::string, int>* dict, Index<int> testDict, std::string str)
{
	int i(0);
	int k(0);
	int pos(0);
	std::string s = "";
	while (i < str.length())
	{
		if (str[i] == ' ')
		{
			if (pos == 0)
				s = str.substr(pos, i);
			else
				s = str.substr(pos + 1, i - pos - 1);
			pos = i;

			assert(dict->Get(s) == testDict.GetDict()->Get(s));
		}
		i++;
	}
}

inline void test52(Dictionary<std::string, int>* dict, Index<int> testDict, std::string str)
{
	std::string s1 = str.substr(0, 52);
	test26(dict, testDict, s1);
	std::string s2 = str.substr(52, 52);
	test8(dict, testDict, s2);

}


inline void test_index()
{
	std::string str26 = "a b c d e f g h i j k l m n o p q r s t u v w x y z ";
	
	Index<int> testStr26_3(str26, 3);
	pair<std::string, int> p;
	p.key = "a";
	p.element = 1;
	Dictionary<std::string, int>* dict_26_3 = new Dictionary<std::string, int>(p);
	dict_26_3->Add("b", 2);
	dict_26_3->Add("c", 2);
	dict_26_3->Add("d", 2);
	dict_26_3->Add("e", 3);
	dict_26_3->Add("f", 3);
	dict_26_3->Add("g", 3);
	dict_26_3->Add("h", 4); 
	dict_26_3->Add("i", 4);
	dict_26_3->Add("j", 4);
	dict_26_3->Add("k", 5);
	dict_26_3->Add("l", 5);
	dict_26_3->Add("m", 5);
	dict_26_3->Add("n", 6);
	dict_26_3->Add("o", 6);
	dict_26_3->Add("p", 6);
	dict_26_3->Add("q", 7);
	dict_26_3->Add("r", 7);
	dict_26_3->Add("s", 7);
	dict_26_3->Add("t", 8);
	dict_26_3->Add("u", 8);
	dict_26_3->Add("v", 8);
	dict_26_3->Add("w", 9);
	dict_26_3->Add("x", 9);
	dict_26_3->Add("y", 9);
	dict_26_3->Add("z", 10);

	Index<int> testStr26_4(str26, 4);
	Dictionary<std::string, int>* dict_26_4 = new Dictionary<std::string, int>(p);
	dict_26_4->Add("b", 1);
	dict_26_4->Add("c", 2);
	dict_26_4->Add("d", 2);
	dict_26_4->Add("e", 2);
	dict_26_4->Add("f", 2);
	dict_26_4->Add("g", 3);
	dict_26_4->Add("h", 3);
	dict_26_4->Add("i", 3);
	dict_26_4->Add("j", 3);
	dict_26_4->Add("k", 4);
	dict_26_4->Add("l", 4);
	dict_26_4->Add("m", 4);
	dict_26_4->Add("n", 4);
	dict_26_4->Add("o", 5);
	dict_26_4->Add("p", 5);
	dict_26_4->Add("q", 5);
	dict_26_4->Add("r", 5);
	dict_26_4->Add("s", 6);
	dict_26_4->Add("t", 6);
	dict_26_4->Add("u", 6);
	dict_26_4->Add("v", 6);
	dict_26_4->Add("w", 7);
	dict_26_4->Add("x", 7);
	dict_26_4->Add("y", 7);
	dict_26_4->Add("z", 7);

	Index<int> testStr26_2(str26, 2);
	Dictionary<std::string, int>* dict_26_2 = new Dictionary<std::string, int>(p);
	dict_26_2->Add("b", 2);
	dict_26_2->Add("c", 2);
	dict_26_2->Add("d", 3);
	dict_26_2->Add("e", 3);
	dict_26_2->Add("f", 4);
	dict_26_2->Add("g", 4);
	dict_26_2->Add("h", 5);
	dict_26_2->Add("i", 5);
	dict_26_2->Add("j", 6);
	dict_26_2->Add("k", 6);
	dict_26_2->Add("l", 7);
	dict_26_2->Add("m", 7);
	dict_26_2->Add("n", 8);
	dict_26_2->Add("o", 8);
	dict_26_2->Add("p", 9);
	dict_26_2->Add("q", 9);
	dict_26_2->Add("r", 10);
	dict_26_2->Add("s", 11);
	dict_26_2->Add("t", 11);
	dict_26_2->Add("u", 12);
	dict_26_2->Add("v", 12);
	dict_26_2->Add("w", 13);
	dict_26_2->Add("x", 13);
	dict_26_2->Add("y", 14);
	dict_26_2->Add("z", 14);

	Index<int> testStr26_5(str26, 5);
	Dictionary<std::string, int>* dict_26_5 = new Dictionary<std::string, int>(p);
	dict_26_5->Add("b", 1);
	dict_26_5->Add("c", 2);
	dict_26_5->Add("d", 2);
	dict_26_5->Add("e", 2);
	dict_26_5->Add("f", 2);
	dict_26_5->Add("g", 2);
	dict_26_5->Add("h", 3);
	dict_26_5->Add("i", 3);
	dict_26_5->Add("j", 3);
	dict_26_5->Add("k", 3);
	dict_26_5->Add("l", 3);
	dict_26_5->Add("m", 4);
	dict_26_5->Add("n", 4);
	dict_26_5->Add("o", 4);
	dict_26_5->Add("p", 4);
	dict_26_5->Add("q", 4);
	dict_26_5->Add("r", 5);
	dict_26_5->Add("s", 5);
	dict_26_5->Add("t", 5);
	dict_26_5->Add("u", 5);
	dict_26_5->Add("v", 5);
	dict_26_5->Add("w", 6);
	dict_26_5->Add("x", 6);
	dict_26_5->Add("y", 6);
	dict_26_5->Add("z", 6);

	pair<std::string, int> p1;
	p1.key = "a ";
	p1.element = 1;
	std::string str1 = "a ";
	Index<int> testStr1_1(str1, 1);
	Dictionary<std::string, int>* dict_1_1 = new Dictionary<std::string, int>(p1);
	

	std::string str8 = "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh ";

	Index<int> testStr8_2(str8, 2);
	Dictionary<std::string, int>* dict_8_2 = new Dictionary<std::string, int>(p);
	dict_8_2->Add("bb", 2);
	dict_8_2->Add("ccc", 2);
	dict_8_2->Add("dddd", 3);
	dict_8_2->Add("eeeee", 3);
	dict_8_2->Add("ffffff", 4);
	dict_8_2->Add("ggggggg", 4);
	dict_8_2->Add("hhhhhhhh", 5);

	Index<int> testStr8_3(str8, 3); 
	Dictionary<std::string, int>* dict_8_3 = new Dictionary<std::string, int>(p);
	dict_8_3->Add("bb", 2);
	dict_8_3->Add("ccc", 2);
	dict_8_3->Add("dddd", 2);
	dict_8_3->Add("eeeee", 3);
	dict_8_3->Add("ffffff", 3);
	dict_8_3->Add("ggggggg", 3);
	dict_8_3->Add("hhhhhhhh", 4);

	Index<int> testStr8_4(str8, 4);
	Dictionary<std::string, int>* dict_8_4 = new Dictionary<std::string, int>(p);
	dict_8_4->Add("bb", 1);
	dict_8_4->Add("ccc", 2);
	dict_8_4->Add("dddd", 2);
	dict_8_4->Add("eeeee", 2);
	dict_8_4->Add("ffffff", 2);
	dict_8_4->Add("ggggggg", 3);
	dict_8_4->Add("hhhhhhhh", 3);

	Index<int> testStr8_8(str8, 8);
	Dictionary<std::string, int>* dict_8_8 = new Dictionary<std::string, int>(p);
	dict_8_4->Add("bb", 1);
	dict_8_4->Add("ccc", 1);
	dict_8_4->Add("dddd", 1);
	dict_8_4->Add("eeeee", 2);
	dict_8_4->Add("ffffff", 2);
	dict_8_4->Add("ggggggg", 2);
	dict_8_4->Add("hhhhhhhh", 2);

	std::string str52 = "a b c d e f g h i j k l m n o p q r s t u v w x y z aa bb cc dd ee ff gg hh ii jj kk ll mm nn oo pp qq rr ss tt uu vv ww xx yy zz ";

	Index<int> testStr52_2(str52, 2);
	Dictionary<std::string, int>* dict_52_2 = new Dictionary<std::string, int>(p);
	dict_52_2->Add("b", 2);
	dict_52_2->Add("c", 2);
	dict_52_2->Add("d", 3);
	dict_52_2->Add("e", 3);
	dict_52_2->Add("f", 4);
	dict_52_2->Add("g", 4);
	dict_52_2->Add("h", 5);
	dict_52_2->Add("i", 5);
	dict_52_2->Add("j", 6);
	dict_52_2->Add("k", 6);
	dict_52_2->Add("l", 7);
	dict_52_2->Add("m", 7);
	dict_52_2->Add("n", 8);
	dict_52_2->Add("o", 8);
	dict_52_2->Add("p", 9);
	dict_52_2->Add("q", 9);
	dict_52_2->Add("r", 10);
	dict_52_2->Add("s", 11);
	dict_52_2->Add("t", 11);
	dict_52_2->Add("u", 12);
	dict_52_2->Add("v", 12);
	dict_52_2->Add("w", 13);
	dict_52_2->Add("x", 13);
	dict_52_2->Add("y", 14);
	dict_52_2->Add("z", 14);

	dict_52_2->Add("aa", 15);
	dict_52_2->Add("bb", 15);
	dict_52_2->Add("cc", 16);
	dict_52_2->Add("dd", 16);
	dict_52_2->Add("ee", 17);
	dict_52_2->Add("ff", 17);
	dict_52_2->Add("gg", 18);
	dict_52_2->Add("hh", 18);
	dict_52_2->Add("ii", 19);
	dict_52_2->Add("jj", 19);
	dict_52_2->Add("kk", 20);
	dict_52_2->Add("ll", 21);
	dict_52_2->Add("mm", 21);
	dict_52_2->Add("nn", 22);
	dict_52_2->Add("oo", 22);
	dict_52_2->Add("pp", 23);
	dict_52_2->Add("qq", 23);
	dict_52_2->Add("rr", 24);
	dict_52_2->Add("ss", 24);
	dict_52_2->Add("tt", 25);
	dict_52_2->Add("uu", 25);
	dict_52_2->Add("vv", 26);
	dict_52_2->Add("ww", 26);
	dict_52_2->Add("xx", 27);
	dict_52_2->Add("yy", 27);
	dict_52_2->Add("zz", 28);

	test26(dict_26_3, testStr26_3, str26);
	test26(dict_26_4, testStr26_4, str26);
	test26(dict_26_2, testStr26_2, str26);
	test26(dict_26_5, testStr26_5, str26);
	
	test8(dict_8_2, testStr8_2, str8);
	test8(dict_8_3, testStr8_3, str8);
	test8(dict_8_4, testStr8_4, str8);
	test52(dict_52_2, testStr52_2, str52);
	


}
