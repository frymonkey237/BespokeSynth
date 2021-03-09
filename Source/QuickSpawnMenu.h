/*
  ==============================================================================

    QuickSpawnMenu.h
    Created: 22 Oct 2017 7:49:16pm
    Author:  Ryan Challinor

  ==============================================================================
*/

#pragma once

#include "IDrawableModule.h"

class QuickSpawnMenu : public IDrawableModule
{
public:
   QuickSpawnMenu();
   virtual ~QuickSpawnMenu();
   
   void Init() override;
   void DrawModule() override;
   void SetDimensions(int w, int h) { mWidth = w; mHeight = h; }
   bool HasTitleBar() const override { return false; }
   string GetTitleLabel() override { return ""; }
   bool IsSaveable() override { return false; }
   string GetHoveredModuleTypeName();
   
   void KeyPressed(int key, bool isRepeat) override;
   void KeyReleased(int key) override;
   void MouseReleased() override;
   
   bool IsSingleton() const override { return true; }
   
private:
   string GetModuleTypeNameAt(int x, int y);
   void OnClicked(int x, int y, bool right) override;
   bool MouseMoved(float x, float y) override;
   void GetDimensions(float& width, float& height) override { width = mWidth; height = mHeight; }
   float mWidth;
   float mHeight;
   std::vector<string> mElements;
   char mCurrentMenuChar;
   int mLastHoverX;
   int mLastHoverY;
};

extern QuickSpawnMenu* TheQuickSpawnMenu;
