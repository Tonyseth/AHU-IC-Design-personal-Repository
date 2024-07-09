def coin_change_min_weight(v, w, y):

    n = len(v)  # 硬币种类数
    
    # 初始化动态规划表
    F = [float('inf')] * (y + 1)
    F[0] = 0
    
    # 用于记录选择的硬币
    choice = [[0] * n for _ in range(y + 1)]
    
    # 动态规划过程
    for j in range(1, y + 1):
        for k in range(n):
            if v[k] <= j:
                if F[j - v[k]] + w[k] < F[j]:
                    F[j] = F[j - v[k]] + w[k]
                    choice[j] = choice[j - v[k]].copy()
                    choice[j][k] += 1
    
    return F[y], choice[y]

# 测试代码
if __name__ == "__main__":
    v_test = [1, 4, 6, 8]  # 硬币面值
    w_test = [1, 2, 4, 6]   # 硬币重量
    y_test = 12             # 需要支付的总价值
    
    min_weight, coin_used = coin_change_min_weight(v_test, w_test, y_test)
    
    print(f"最小总重量: {min_weight}")
    print("使用的硬币:")
    for i, count in enumerate(coin_used):
        if count > 0:
            print(f"面值 {v_test[i]}: {count} 个")