#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <locale.h>
#include <sysinfoapi.h>
#include <intrin.h>


int main() {
    setlocale(LC_ALL, "ru");
    TCHAR buffer[256] = TEXT("");
    DWORD nSize = _countof(buffer);
    if (!GetComputerName(buffer, &nSize))
        _tprintf_s(TEXT("GetComputerName"));
    _tprintf(TEXT("Computer___name___: %s\n"), buffer);

    if (!GetUserName(buffer, &nSize))
        _tprintf_s(TEXT("GetUserName"));
    _tprintf(TEXT("User___name___: %s\n"), buffer);

    SYSTEM_INFO sysInf;
    GetSystemInfo(&sysInf);
    printf_s("CPU___Brand___: \n");
    wprintf_s(L"    OEM ID: %d\n", sysInf.dwOemId);
    wprintf_s(L"    Number of processors: %d\n", sysInf.dwNumberOfProcessors);
    wprintf_s(L"    Page size: %d\n", sysInf.dwPageSize);
    wprintf_s(L"    Processor type: %d\n", sysInf.dwProcessorType);
    wprintf_s(L"    Minimum application address: %p\n", sysInf.lpMinimumApplicationAddress);
    wprintf_s(L"    Maximum application address: %p\n", sysInf.lpMaximumApplicationAddress);
    wprintf_s(L"    Active processor mask: %I64u\n", sysInf.dwActiveProcessorMask);
    return 0;
}