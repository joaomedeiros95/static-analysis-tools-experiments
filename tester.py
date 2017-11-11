#!/usr/bin/python3.6
import argparse
import re
import sys
import subprocess
import os
import json

parser = argparse.ArgumentParser(description='Test simple programas with static analysis tools')
parser.add_argument('-f', help='the file name to analise')
parser.add_argument('-e', help='exclude', default='')

JAVA_COMMANDS = [{"pmd": "sh /home/joao/UFRN/TCC/Ferramentas/Java/pmd-bin-5.8.1/bin/run.sh pmd -d {} -R java-android,java-basic,java-braces,java-clone,java-codesize,java-comments,java-controversial,java-coupling,java-design,java-empty,java-finalizers,java-imports,java-j2ee,java-javabeans,java-junit,java-logging-jakarta-commons,java-logging-java,java-migrating,java-naming,java-optimizations,java-strictexception,java-strings,java-sunsecure,java-typeresolution,java-unnecessary,java-unusedcode -f text"},
				 {"checkstyle": "java -jar /home/joao/UFRN/TCC/Ferramentas/Java/checkstyle-8.3-all.jar -c /sun_checks.xml {}"},
				 {"checkstyle_google": "java -jar /home/joao/UFRN/TCC/Ferramentas/Java/checkstyle-8.3-all.jar -c /google_checks.xml {}"}]

PYTHON_COMMANDS = [{"pylint": "pylint {}"},
				   {"pyflakes": "python -m pyflakes {}"},
				   {"bandit": "bandit {}"},
				   {"pycodestyle": "pycodestyle {}"},
				   {"Python Taint": "python -m pyt -f {}"},
				   {"pychecker": "pychecker {}"}]

C_COMMANDS = [{"cppcheck": "cppcheck --enable=all {}"},
			  {"flawfinder": "flawfinder {}"},
			  {"oclint": "oclint {}"},
			  {"splint": "splint {}"}]

LANGUAGES = ["c", "java", "python"]

EXTENSION_PER_LANG = {
	"c": ".c",
	"java": ".java",
	"python": ".py"
}

ROOT_PATH = "/home/joao/UFRN/TCC/static-analysis-tools-experiments/"

RESULTS_PATH = ROOT_PATH + "results/"

RESULT_NAME = "%s.txt"

COMPILE_COMMANDS = [
	{
	  "directory": "/home/joao/UFRN/TCC/static-analysis-tools-experiments/c/",
	}
]

GCC_COMMAND = "gcc %s"
FILE_COMMAND = ROOT_PATH + "c/" + "%s"
COMPILE_COMMANDS_FILE = ROOT_PATH + "compile_commands.json"

args = parser.parse_args()
file_name = args.f
exclude = args.e.split(',')

def write_result(result, error, language, tool):
	file_dir = RESULTS_PATH + language + "/" + file_name + "/"
	name_file = RESULT_NAME % tool
	result_file = file_dir + name_file

	if not os.path.exists(file_dir):
	    os.makedirs(file_dir)

	with open(result_file, 'wb') as outfile:
		outfile.write(result)
		if error:
			outfile.write(error)

def write_compile_commands():
	c_file_name = file_name + ".c"
	COMPILE_COMMANDS[0]['command'] = GCC_COMMAND % c_file_name
	COMPILE_COMMANDS[0]['file'] = FILE_COMMAND % c_file_name

	with open(COMPILE_COMMANDS_FILE, 'w') as file:
		json.dump(COMPILE_COMMANDS, file)


def run_tests(tests_to_run, path_to_run, language):
	for test in tests_to_run:
		tool  = next(iter(test))
		command = test[tool]
		command = command.format(path_to_run)
		command = command.split()

		print(tool)
		process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, bufsize=1)
		result, error = process.communicate()

		write_result(result, error, lang, tool)

def get_tests_by_language(language):
	if language in "java":
		tests_to_run = JAVA_COMMANDS
	elif language in "python":
		tests_to_run = PYTHON_COMMANDS
	elif language in "c":
		tests_to_run = C_COMMANDS
	else:
		print("You should specify a valid language")

	return tests_to_run

if __name__ == '__main__':
	write_compile_commands()
	for lang in LANGUAGES:
		if lang in exclude:
			continue
		path_to_file = ROOT_PATH + lang + "/" + file_name + EXTENSION_PER_LANG[lang]
		tests_to_run = get_tests_by_language(lang)

		run_tests(tests_to_run, path_to_file, lang)
