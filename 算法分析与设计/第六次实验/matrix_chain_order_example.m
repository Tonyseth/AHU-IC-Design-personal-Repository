function matrix_chain_order_example()
    INT_MAX = 2147483647;
    M = 7;
    
    p = [30, 35, 15, 5, 10, 20, 25];
    
    % Initialize m and s matrices
    m = zeros(M, M);
    s = zeros(M, M);
    
    [m, s] = matrix_chain_order(p, M, m, s);
    
    fprintf('当 n=6 时最优解为: %d\n', m(1, 6));
    fprintf('括号化方案为：\n');
    print_optimal_parens(s, 1, 6);
end

function [m, s] = matrix_chain_order(p, M, m, s)
    INT_MAX = 2147483647;
    n = M - 1;
    
    for i = 1:n
        m(i, i) = 0;
    end
    
    for l = 2:n  % 矩阵链的长度
        for i = 1:n-l+1
            j = i + l - 1;  % 等价于 l = j - i + 1
            m(i, j) = INT_MAX;
            
            for k = i:j-1
                q = m(i, k) + m(k+1, j) + p(i)*p(k+1)*p(j+1);
                if q < m(i, j)
                    m(i, j) = q;
                    s(i, j) = k;
                end
            end
        end
    end
end

function print_optimal_parens(s, i, j)
    if i == j
        fprintf('A%d', i);
    else
        fprintf('(');
        print_optimal_parens(s, i, s(i, j));
        print_optimal_parens(s, s(i, j) + 1, j);
        fprintf(')');
    end
end