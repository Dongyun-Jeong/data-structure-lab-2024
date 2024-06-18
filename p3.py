# 프로젝트 문제 3번
input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

forest = []

from collections import deque

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0
    # 입력 힌트

    # forest 리스트를 input 리스트로 초기화
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0
    print("곰의 초기 위치 x : {0}, y : {1}".format(bear_x, bear_y))

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    def bfs(x, y, size):
        visited = [[False] * N for _ in range(N)]
        queue = deque([(x, y, 0)])  # (x, y, 이동 시간)
        visited[x][y] = True
        possible_targets = []

        while queue:
            cx, cy, dist = queue.popleft()
            for dx, dy in directions:
                nx, ny = cx + dx, cy + dy
                if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                    if forest[nx][ny] <= size:
                        visited[nx][ny] = True
                        if 0 < forest[nx][ny] < size:
                            possible_targets.append((dist + 1, nx, ny))
                        queue.append((nx, ny, dist + 1))

        if possible_targets:
            possible_targets.sort()
            return possible_targets[0]  # (거리, x, y)
        return None

    while True:
        target = bfs(bear_x, bear_y, bear_size)
        if not target:
            break  # 먹을 수 있는 벌집이 없으면 종료

        dist, tx, ty = target
        time += dist
        bear_x, bear_y = tx, ty
        honeycomb_count += 1
        forest[tx][ty] = 0  # 벌집을 먹고 빈칸으로 변경

        # 곰의 크기를 증가시킬지 확인
        if honeycomb_count == bear_size:
            bear_size += 1
            honeycomb_count = 0

    #여기에서부터 코드를 작성하세요.

    return time

result = problem3(input)

assert result == 14
print("정답입니다.")
