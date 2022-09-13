void Chuan_Hoa_Name(char a[])
{
    int n = strlen(a);
    // Xóa khoảng trắng đầu chuỗi
    while (a[0] == ' ')
    {
        if (a[0] == ' ')
        {
            for (int i = 0; i < n; i++)
            {
                a[i] = a[i + 1];
            }
        }
    }
    // Xóa khoảng trắng cuối chuỗi
    while (a[n - 1] == ' ')
    {
        if (a[n - 1] == ' ')
        {
            a[n - 1] = '\0';
        }
    }
    // Xóa khoảng trắng ở giữa
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == ' ')
        {
            if (a[i + 1] == ' ')
            {
                for (int j = i; j < n; j++)
                {
                    a[j] = a[j + 1];
                }
                i--;
            }
        }
        i++;
    }
    strlwr(a);
    a[0] = toupper(a[0]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ' ')
        {
            a[i + 1] = toupper(a[i + 1]);
        }
    }
    // cout << "Name chuan hoa: " << a << endl;
}
