def sum_arrangements(num):
    num_str = str(num)
    sum_a = sum([int(x) for x in num_str])
    gt = 1
    mu_10 = 1
    res = 0
    for (i, x) in enumerate(num_str):
        res += sum_a * mu_10
        mu_10 *= 10
        if i != 0:
            gt *= i
    
    return res * gt

print(sum_arrangements(89))
print(sum_arrangements(1185))