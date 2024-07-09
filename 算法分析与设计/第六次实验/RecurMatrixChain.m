function [result, s] = RecurMatrixChain(P, i, j)
    % 初始化 m 和 s 矩阵
    n = length(P) - 1;
    m = inf(n, n);
    s = zeros(n, n);

    % 调用递归函数并返回 m(i, j)
    [result, m, s] = RecurMatrixChainRecursive(m, s, P, i, j);
end

function [result, m, s] = RecurMatrixChainRecursive(m, s, P, i, j)

    if m(i, j) < inf
        result = m(i, j);
        return;
    end

    if i == j
        m(i, j) = 0;
    else

        for k = i:j - 1
            [m(i, k), m, s] = RecurMatrixChainRecursive(m, s, P, i, k);
            [m(k + 1, j), m, s] = RecurMatrixChainRecursive(m, s, P, k + 1, j);
            q = m(i, k) + m(k + 1, j) + P(i) * P(k + 1) * P(j + 1);

            if q < m(i, j)
                m(i, j) = q;
                s(i, j) = k;
            end

        end

    end

    result = m(i, j);
end

% function print_optimal_parens(s, i, j)
% 
%     if i > size(s, 1) || j > size(s, 2)
%         error('Index out of bounds');
%     end
% 
%     if i == j
%         fprintf('A%d', i);
%     else
%         fprintf('(');
%         print_optimal_parens(s, i, s(i, j));
%         print_optimal_parens(s, s(i, j) + 1, j);
%         fprintf(')');
%     end
% 
% end
