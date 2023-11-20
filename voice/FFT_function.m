function X = DFT_function(x)
    N = length(x); % 신호 x의 길이 N
    X = zeros(N, 1); % 변환 결과를 저장할 벡터 X 초기화
    
    for k = 1:N
        sum = 0;
        for n = 1:N
            % 삼각함수와 복소수의 관계를 사용하여 푸리에 계수 계산
            angle = -2 * pi * (n-1) * (k-1) / N;
            sum = sum + x(n) * (cos(angle) + 1i * sin(angle)); % e^(i*theta) = cos(theta) + i*sin(theta)
        end
        X(k) = sum;
    end
end
