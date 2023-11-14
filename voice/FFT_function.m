function Y = FFT_function(x)
    N = length(x);
    if N <= 1
        Y = x;
    else
        % 짝수와 홀수 인덱스 요소 분리
        even = FFT_function(x(1:2:end));
        odd = FFT_function(x(2:2:end));
        
        % 단위근의 계수 계산
        factor = exp(-2j * pi * (0:N/2-1) / N);
        
        % FFT 결과 합치기
        Y = [even + factor .* odd, even - factor .* odd];
    end
end
