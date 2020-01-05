def sumyeah(x,y):
    z = x + y
    return z


# 计算斐波那契数列，同时为了用上条件判断语句，当数列中出现3时，把它变为1并以1进行后续的数列计算
# 输出结果为[1, 1, 2, 1, 1, 2, 1]
numbers = [1, 1, 0, 0, 0, 0, 0]
for i in range(2, 7):
    numbers[i] = sumyeah(numbers[i-1], numbers[i-2])
    if numbers[i] == 3:
        numbers[i] = 1
print(numbers)
