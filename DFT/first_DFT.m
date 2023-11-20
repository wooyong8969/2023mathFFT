function X = first_DFT(x)
    N = length(x);
    X = zeros(N, 1);
    
    for k = 1:N
        for n = 1:N
            X(k) = X(k) + x(n) * exp(-1i * 2 * pi * (k-1) * (n-1) / N);
        end
    end
end