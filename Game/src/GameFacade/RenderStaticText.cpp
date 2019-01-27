#include "RenderStaticText.h"


void RenderStaticText::updateValues(int enemies, int fps, float life, int score)
{
    wchar_t* text = (wchar_t*)L"Enemies loaded: ";
    this->enemies->setText(text);

    text = (wchar_t*)L"FPS: ";
    this->fps->setText(text);

    text = (wchar_t*)L"Life: ";
    this->life->setText(text);

    text = (wchar_t*)L"Score: ";
    this->score->setText(text);
}