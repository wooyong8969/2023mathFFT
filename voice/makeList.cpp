#include <stdio.h>
#include <string.h>

#define MAX_FILES 200 
#define MAX_PHONEMES 7

typedef struct {
    char phoneme[10];    // 음운 이름
    int files[MAX_FILES]; // 해당 음운이 포함된 파일 번호 리스트
    int count;          // 해당 음운을 포함하는 파일의 수
} PhonemeList;

int main() {
    PhonemeList phonemeLists[MAX_PHONEMES] = {
        {"/tiy/", {0}, 0},
        {"/iy/", {0}, 0},
        {"/piy/", {0}, 0},
        {"/m/", {0}, 0},
        {"/n/", {0}, 0},
        {"/diy/", {0}, 0},
        {"/uw/", {0}, 0}
    };
    
    char input[4]; // 입력받을 음운
    int fileNumber = 0; // 파일 번호

    printf("Enter the phoneme labels for each file (Enter 'done' to finish):\n");
    while (fileNumber < MAX_FILES) {
        // 사용자로부터 음운 입력받기
        scanf("%s", input);
        
        // 입력 종료 조건 확인
        if (strcmp(input, "done") == 0) {
            break;
        }

        // 해당하는 음운을 찾고 파일 번호를 리스트에 추가
        for (int i = 0; i < MAX_PHONEMES; ++i) {
            if (strcmp(phonemeLists[i].phoneme, input) == 0) {
                phonemeLists[i].files[phonemeLists[i].count] = fileNumber;
                phonemeLists[i].count++;
                break;
            }
        }

        // 다음 파일 번호로 이동
        fileNumber++;
    }

    // 입력받은 음운 정보를 출력
    for (int i = 0; i < MAX_PHONEMES; ++i) {
        printf("%s: ", phonemeLists[i].phoneme);
        for (int j = 0; j < phonemeLists[i].count; ++j) {
            printf("%d, ", phonemeLists[i].files[j]);
        }
        printf("\n");
    }

    return 0;
}

/*
c
*/
