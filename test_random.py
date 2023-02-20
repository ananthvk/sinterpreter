from randexpr import Generator
import subprocess

APP = 'main'

g = Generator(
    term_op=["*"],
    max_recursion=20,
    int_lim=(-20, 20)
)
n = 200

n_overflows = 0
n_incorrect = 0
n_correct = 0

print(f'Running {n} random tests and comparing with eval()')

step = n // 10

for i in range(n):
    expression = g.generate()
    evaluated = eval(expression)

    op = subprocess.getoutput("echo \"" + expression + "\"|" + " ./" + APP)

    """
    if(str(evaluated) == str(op.strip())):
        print('Correct')
    """
    

    if(str(evaluated) != str(op.strip())):

        if('overflow' in op):
            #print('INT OVERFLOW')
            n_overflows += 1
        else:
            print(f'Evaluating {expression}, ', end ='')
            print(f'Expected {evaluated}, Got {op}')
            n_incorrect += 1
    else:
        n_correct += 1
    
    if(i % step == 0):
        print(f'{i} tests completed')

print(f'Total number of tests:{n}')
print(f'Total number of tests failed:{n_incorrect}')
print(f'Total number of tests overflow:{n_overflows}')
print(f'Total number of tests passed:{n_correct}')
print(f'Percentage sucess:{(n_correct/n)*100:0.6} %')
