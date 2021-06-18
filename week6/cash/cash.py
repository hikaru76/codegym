from cs50 import get_float

cash = 0
cnt = 0
while cash < 0.0099:
    cash = get_float("Change owed: ")
cash = int(cash * 100)
while cash >= 25:
    cnt += 1
    cash -= 25
while cash >= 10:
    cnt += 1
    cash -= 10
while cash >= 5:
    cnt += 1
    cash -= 5
while cash > 0:
    cnt += 1
    cash -= 1
print(cnt)
