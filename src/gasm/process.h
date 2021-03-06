//
// Created by gurth on 9/16/20.
// Do command treatment, include initialization of virtual data segment,
// stack segment and register status, preparing prefix and suffix code.
//

#ifndef STRUCT_SYSTEM_INFO
#define STRUCT_SYSTEM_INFO

struct offset_info          // Offset information: the data offset in
                            // prefix code or suffix code. Need set manually.
{
    short pre_rsp_save=0x05;
    short pre_rsp=0x0f;
    short pre_rax=0x1c;

    short suf_rax=0x02;
    short suf_rsp=0x0f;
    short suf_rsp_save=0x19;
};

typedef struct offset_info offset_info;

struct system_info       // System information: main information of gasm
{
    unsigned long long mem;      // Virtual memeray length
    unsigned long long stack;    // Virtual stack length
    unsigned long long data;     // Virtual data length
    short exe_buff;              // Execution buffer length
    short prefix;                // Prefix code length
    short suffix;                // Suffix code length
    offset_info offset;          // Offset information
};

typedef struct system_info system_info;

#endif //STRUCT_SYSTEM_INFO

#ifndef GASM_PROCESS_H
#define GASM_PROCESS_H

#include "translate.h"
#include "register.h"
#include <fstream>

typedef __attribute__((naked)) void(*EX)(void); // Function pointer to execution buffer

class Process
{
private:
    void* exe_buff= nullptr;   // Execution buffer
    void* exe_cmd= nullptr;    // Execution command
    void* vmem= nullptr;       // Virtual Memory
    void* data_seg= nullptr;   // Data segment
    void* stack_seg= nullptr;  // Stack segment
    void* code_seg= nullptr;   // Code segment
    size64 code_offset=0;      // COde offset in code seg
    EX ex;                     // Execute address
    system_info this_info;     // Process information
    constexpr static const system_info default_info={0x2000000, 0x2000,0x40000};
                               // Default system information
    char* prefix= nullptr;     // Prefix code, need to be copied to exe_buff
    char* suffix= nullptr;     // Suffix code, need to be copied to exe_buff
    std::ifstream gasmfile;    // Input file stream
    Register regprevious;      // Store previous register status
private:
    void GetConfig(std::string configfile);   // Get config form file
    void LoadCode(std::string filename);      // Load code from file to code seg
public:
    int input_mode=0;          // Input mode, 0: /dev/stdin 1: gasmfile
public:
    Process();                 // Constructor function, call init()
    Process(system_info sysinfo);       // Constructor function, set custom system_info asn call init()
    ~Process();                // Destructor function， cal uninit()
    void CmdParsing(std::string cmd);            // Parsing command
    void ShowRegisterStatus();                   // Show register status
    void ShowRecommendInfo();                    // Show recommend information
    void ShowVirtualMemoryStruct();              // Show virtual memory struct, data, stack ang code segment
    void ShowHelpInfo();                         // Show help information
    void ArgParsing(int argc, char * argv[]);    // Parsing parameters from main()
    void FillCmdFromFile(std::string& buff);     // Fill command
    bool init();               // Do initialization
    bool uninit();             // Release initialization
};


#endif //GASM_PROCESS_H
