#include <stdio.h>
#include <string.h>

#define MAX_FILES 200 
#define MAX_PHONEMES 7

typedef struct {
    char phoneme[10];    // ���� �̸�
    int files[MAX_FILES]; // �ش� ������ ���Ե� ���� ��ȣ ����Ʈ
    int count;          // �ش� ������ �����ϴ� ������ ��
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
    
    char input[4]; // �Է¹��� ����
    int fileNumber = 0; // ���� ��ȣ

    printf("Enter the phoneme labels for each file (Enter 'done' to finish):\n");
    while (fileNumber < MAX_FILES) {
        // ����ڷκ��� ���� �Է¹ޱ�
        scanf("%s", input);
        
        // �Է� ���� ���� Ȯ��
        if (strcmp(input, "done") == 0) {
            break;
        }

        // �ش��ϴ� ������ ã�� ���� ��ȣ�� ����Ʈ�� �߰�
        for (int i = 0; i < MAX_PHONEMES; ++i) {
            if (strcmp(phonemeLists[i].phoneme, input) == 0) {
                phonemeLists[i].files[phonemeLists[i].count] = fileNumber;
                phonemeLists[i].count++;
                break;
            }
        }

        // ���� ���� ��ȣ�� �̵�
        fileNumber++;
    }

    // �Է¹��� ���� ������ ���
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
