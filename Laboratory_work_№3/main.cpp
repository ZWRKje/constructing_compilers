#include <iostream>
#include <regex>
#include <locale>
#include <vector>

void check(std::vector<std::string> task, std::string regExpr) {
	std::regex regex(regExpr);
	std::cout << "Регулярное выражение = " << regExpr << std::endl;

	for (const std::string& string : task)
	{
		std::cout << "regex_match\t" << string << "\t\t" << std::regex_match(string, regex) << std::endl;
	}
	//std::cout << std::endl;
}




int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tЗадание №1\t" << std::endl;
	std::vector<std::string> task1 = { "abcdefg", "abcde", "abc" };
	std::string regExpr1 = "abc[a-z]{0,4}";
	check(task1, regExpr1);
	std::cout << std::endl;

	std::cout << "\tЗадание №1.2\t" << std::endl;
	std::vector<std::string> task1_2 = { "abc123xyz", "define \"123\"", "var g = 123;" };
	std::string exp1_2 = "\\D*\\d{3}\\D*";
	check(task1_2, exp1_2);
	std::cout << std::endl;

	std::cout << "\tЗадание №2\t" << std::endl;
	std::vector<std::string> task2 = { "cat.", "896.", "?=+.", "abc1" };
	std::string exp2 = ".*\\..*";
	check(task2, exp2);
	std::cout << std::endl;

	std::cout << "\tзадание №3\t" << std::endl;
	std::vector<std::string> task3 = { "can", "man", "fan", "dan", "ran", "pan" };
	std::string exp3 = "[cmf]an";
	check(task3, exp3);
	std::cout << std::endl;

	std::cout << "\tЗадание №4\t" << std::endl;
	std::vector<std::string> task4 = { "hog", "dog", "bog" };
	std::string exp4 = "[^b]og";
	check(task4, exp4);
	std::cout << std::endl;

	std::cout << "\tЗадание №5\t" << std::endl;
	std::vector<std::string> task5 = { "Ana", "Bob", "Cpc", "aax", "bby", "ccz" };
	std::string exp5 = "[A-Z][A-z]{2}";
	check(task5, exp5);
	std::cout << std::endl;

	std::cout << "\tЗадание №6\t" << std::endl;
	std::vector<std::string> task6 = { "wazzzzzup", "wazzzup", "wazup" };
	std::string exp6 = "waz{2,}up";
	check(task6, exp6);
	std::cout << std::endl;

	std::cout << "\tЗадание №7\t";
	std::vector<std::string> task7 = { "aaaabcc", "aabbbbc", "aacc", "a" };
	std::string exp7 = "a+b*c+";
	check(task7, exp7);
	std::cout << std::endl;

	std::cout << "\tзадание №8\t";
	std::vector<std::string> task8 = { "1 file found?", "2 files found?", "24 files found?", "no files found." };
	std::string exp8 = "\\d+ files? found\\?";
	check(task8, exp8);
	std::cout << std::endl;

	std::cout << "\tЗадание №9\t";
	std::vector<std::string> task9 = { "1.   abc", "2.	abc", "3.           abc", "4.abc" };
	std::string exp9 = "\\d.\\s+\\S+";
	check(task9, exp9);
	std::cout << std::endl;

	std::cout << "\tЗадание №10\t";
	std::vector<std::string> task10 = { "Mission: successful",
										"Last Mission: unsuccessful",
										"Next Mission: successful upon capture of target" };
	std::string exp10 = "\.* successful$";
	check(task10, exp10);
	std::cout << std::endl;

	std::cout << "\tЗадание №11\t";
	std::vector<std::string> task11 = { "file_record_transcript.pdf", "file_07241999.pdf", "testfile_fake.pdf.tmp" };
	std::string exp11 = "^(\.*)\\.pdf$";
	check(task11, exp11);
	std::cout << std::endl;

	std::cout << "\tЗадание №12\t";
	std::vector<std::string> task12 = { "Jan 1987", "May 1969", "Aug 2011" };
	std::string exp12 = "([A-Z][a-z]{2} (\\d{4}))";
	check(task12, exp12);
	std::cout << std::endl;

	std::cout << "\tЗадание №13\t";
	std::vector<std::string> task13 = { "1280x720", "1920x1600", "1024x768" };
	std::string exp13 = "(\\d+)x(\\d+)";
	check(task13, exp13);
	std::cout << std::endl;

	std::cout << "\tЗадание №14\t";
	std::vector<std::string> task14 = { "I love cats", "I love dogs", "I love logs", "I love cogs" };
	std::string exp14 = "I love ((cat)|(dog))s";
	check(task14, exp14);
	std::cout << std::endl;
	return 0;
}