% 测试代码
v_test = [1, 4, 6, 8];  % 硬币面值
w_test = [1, 2, 4, 6];   % 硬币重量
y_test = 12;             % 需要支付的总价值
[minWeight, coinUsed] = coinChangeMinWeight(v_test, w_test, y_test);
fprintf('最小总重量: %d\n', minWeight);
fprintf('使用的硬币:\n');
for i = 1:length(v_test)
    if coinUsed(i) > 0
        fprintf('面值 %d: %d 个\n', v_test(i), coinUsed(i));
    end
end
function [minWeight, coinUsed] = coinChangeMinWeight(v, w, y)
    n = length(v);  % 硬币种类数
    % 初始化动态规划表
    F = inf(n+1, y+1);
    F(:, 1) = 0;  % 修正：将第一列（总价值为0）初始化为0
    % 用于记录选择的硬币
    choice = zeros(n+1, y+1);
    % 动态规划过程
    for k = 2:n+1
        for j = 1:y+1
            % 不选择第k种硬币
            F(k, j) = F(k-1, j);
            
            % 如果可以选择第k种硬币
            if j > v(k-1)
                if F(k, j-v(k-1)) + w(k-1) < F(k, j)
                    F(k, j) = F(k, j-v(k-1)) + w(k-1);
                    choice(k, j) = 1;
                end
            end
        end
    end
    % 回溯找出使用的硬币
    minWeight = F(n+1, y+1);
    coinUsed = zeros(1, n);
    j = y+1;
    for k = n+1:-1:2
        while choice(k, j) == 1
            coinUsed(k-1) = coinUsed(k-1) + 1;
            j = j - v(k-1);
        end
    end
end