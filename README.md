# snake-game


**컴파일 & 링킹 명령어** `./make` <br>

**실행 명령어** `./main` <br>

**[Stage 1]**
- ncurses를 이용하여 map을 표시한다.
- map 가에는 immune wall, wall, map의 나머지 부분에는 road가 존재한다.
- map에는 길이 3인 snake가 존재한다.
<br>

**[Stage 2]**
- map의 snake는 방향키를 입력받아 일정 틱마다 해당 방향으로 이동한다.
- 방향키의 입력이 없으면 기존 이동방향으로 이동한다.
- 이동 방향의 반대 방향키를 입력하는 경우 게임 오버
- wall에 닿은 경우 게임 오버
<br>

**[Stage 3]**
- map에는 일정 시간마다 item이 등장한다.
- growth item을 먹을 경우 snake의 길이가 1 증가한다.
- poison item을 먹을 경우 snake의 길이가 1 감소한다.
- snake의 길이가 2 이하인 경우 게임 오버
