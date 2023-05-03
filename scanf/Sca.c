#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int vr_scanf(const char* str, void* a, void* b, void* c, void* d, void* e)
{
    char input_str[1024];
    char* token;
    int index = 0;

    fgets(input_str, sizeof(input_str), stdin);  // gets_s()�� fgets()�� ��ü�Ͽ����ϴ�.

    // �Էµ� ���ڿ��� �Ľ��Ͽ� ������ �����մϴ�.
    token = strtok(input_str, " |,");
    while (token != NULL && index < 5) {
        switch (index) {
        case 0:
            if (sscanf_s(token, "%d", (int*)a) != 1) return -1;
            break;
        case 1:
            if (sscanf_s(token, "%c", (char*)b) != 1) return -1;
            break;
        case 2:
            if (sscanf_s(token, "%f", (float*)c) != 1) return -1;
            break;
        case 3:
            if (sscanf_s(token, "%s", (char*)d) != 1) return -1;
            break;
        case 4:
            if (sscanf_s(token, "%s", (char*)e) != 1) return -1;
            break;
        }
        token = strtok_s(NULL, 3969," |,");
        index++;
    }

    if (index != 5) return -1;  // �Էµ� ������ ���� 5���� �ƴ� ��� ������ ��ȯ�մϴ�.

    return 0;
}

int main()
{
    int a;
    char b;
    float c;
    char d[1024];
    char e[1024];

    printf("Enter values: ");
    int result = vr_scanf("%d|%c %f,%s,%s", &a, &b, &c, d, e);

    if (result == 0)
        printf("Values entered: %d %c %f %s %s\n", a, b, c, d, e);
    else
        printf("Error\n");

    return 0;
}
