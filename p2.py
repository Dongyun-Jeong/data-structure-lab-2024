# 프로젝트 문제 2번
input = ")))()"

def problem2(input):

    stack = []
    count = 0
    result = 0

    for char in input:
        print(char)
        
        if char == '(' :
            stack.append(char)
        else :
            if stack :
                stack.pop()
            else :
                count += 1
    
    count += len(stack)

    result = count
    return result

result = problem2(input)

assert result == 3
print("정답입니다.")