P = [30, 35, 15, 5, 10, 20, 25];
[i, j] = size(P);
[result, s] = RecurMatrixChain(P, 1, j - 1);
fprintf('最优解为: %d\n', result);
fprintf('括号化方案为：\n');
print_optimal_parens(s, 1, j - 1);
function print_optimal_parens(s, i, j)
    if i > size(s, 1) || j > size(s, 2)
        error('Index out of bounds');
    end
    if i == j
        fprintf('A%d', i);
    else
        fprintf('(');
        print_optimal_parens(s, i, s(i, j));
        print_optimal_parens(s, s(i, j) + 1, j);
        fprintf(')');
    end
end

