#include "Form1.h"

using namespace CppCLR_WinformsProject1;

[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Form1());
    return 0;
}
