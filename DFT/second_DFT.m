function G = second_DFT(f, T)
    % f는 시간 도메인의 샘플 데이터
    % T는 샘플링된 데이터의 전체 시간 (여기서는 주기가 아니라 샘플링 범위)
    fs = 1 / (T(2) - T(1)); % 샘플링 주파수
    L = length(f); % 샘플의 수
    G = zeros(L, 1); % 변환 결과를 저장할 복소수 벡터
    
    for k = 1:L
        for n = 1:L
            G(k) = G(k) + f(n) * exp(-1i * 2 * pi * (k-1) * (n-1) / L);
        end
    end
    
    % 주파수 벡터 생성 (단측 스펙트럼)
    f = (0:L-1)*(fs/L);
    
    % 주파수 도메인의 결과 반환
    G = G / L; % 결과를 샘플 수로 정규화
end
