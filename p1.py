# 프로젝트 문제 1번
input = [10, 40, 30, 60, 30]

def problem1(input):

    mean = 0
    median = 0
    result = [0,0]

    mean = sum(input) / len(input)
    sorted_input = sorted(input)
    length = len(sorted_input)

    mid = length // 2
    median = sorted_input[mid]
    
    result = [mean, median]
    return result

result = problem1(input)

assert result == [34, 30]
print("정답입니다.")