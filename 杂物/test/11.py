import multiprocessing
import random
import time

# 定义石头、剪刀、布的值
ROCK = 0
SCISSORS = 1
PAPER = 2

# 定义胜负规则
RULES = {
    (ROCK, SCISSORS): 1,
    (SCISSORS, PAPER): 1,
    (PAPER, ROCK): 1,
    (SCISSORS, ROCK): -1,
    (PAPER, SCISSORS): -1,
    (ROCK, PAPER): -1,
    (ROCK, ROCK): 0,
    (SCISSORS, SCISSORS): 0,
    (PAPER, PAPER): 0,
}

# 共享内存存放比赛结果
results = multiprocessing.Array('i', range(100))

def play_game(player_id, results):
    for i in range(len(results)):
        move = random.randint(0, 2)
        while move not in [ROCK, SCISSORS, PAPER]:
            move = random.randint(0, 2)
        results[i] = move
        time.sleep(0.1)

def referee_game(results):
    win_count = 0
    loss_count = 0
    draw_count = 0

    for i in range(len(results)):
        opponent_move = results[i]
        player_move = random.randint(0, 2)
        while player_move not in [ROCK, SCISSORS, PAPER]:
            player_move = random.randint(0, 2)

        result = RULES.get((player_move, opponent_move), 0)
        if result == 1:
            win_count += 1
        elif result == -1:
            loss_count += 1
        else:
            draw_count += 1

    print("玩家1胜利次数:", win_count)
    print("玩家2失败次数:", loss_count)
    print("平局次数:", draw_count)

if __name__ == '__main__':
    results = multiprocessing.Array('i', range(100))

    player1_process = multiprocessing.Process(target=play_game, args=(1, results))
    player2_process = multiprocessing.Process(target=play_game, args=(2, results))

    referee_process = multiprocessing.Process(target=referee_game, args=(results,))

    player1_process.start()
    player2_process.start()
    referee_process.start()

    player1_process.join()
    player2_process.join()
    referee_process.join()
