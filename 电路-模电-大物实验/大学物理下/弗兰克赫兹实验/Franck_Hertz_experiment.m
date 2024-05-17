%Franck–Hertz experiment plot
U_G2K=[49.0 50.0 51.0 52.0 53.0 54.8 56.0 57.0 58.0 59.2 60.4 61.6 62.8 64.0 65.2];
I_A=[8.07 11.03 13.83 16.10 17.69 18.83 18.17 16.43 13.55 10.96 13.88 19.39 24.67 28.77 31.39];
plot(U_G2K, I_A, '.-', 'LineWidth', 2, 'Color', 'k')
%横坐标为加速电压U_G2K，纵坐标为电流I_A
%xlabel('加速电压U_G2K/V')
%ylabel('电流I_A/A')
xlabel('$U_{G2K}/V$', 'Interpreter', 'latex')
ylabel('$I_{A}/A$', 'Interpreter', 'latex')
grid on
xticks(min(U_G2K):1:max(U_G2K))
yticks(min(I_A):1:max(I_A))
title('自动')