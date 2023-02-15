# A simple test of arithmetic expression evaluator
# Note: eval() is potentially unsafe, but as its used only for testing, I am using it
import subprocess
import re
TEST_INPUT = "test1.txt"
APP = "main"

op = subprocess.getoutput("./" + APP + " < " + TEST_INPUT)
results = op.split("\n")

line_no = 0
with open(TEST_INPUT, "r") as test_file:
    for actual_line_no, line in enumerate(test_file):

        # Not an empty line
        if line.strip() != "" and not line.startswith("#"):
            # Remove leading zeros
            line = re.sub(r'\b0+(?!\b)', '', line)
            result = eval(line)
            if results[line_no] != str(result):
                print(f'{actual_line_no+1}: {line.rstrip()}: Expected "{result}", Found "{results[line_no]}"')

            line_no += 1