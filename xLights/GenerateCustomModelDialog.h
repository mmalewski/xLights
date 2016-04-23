#ifndef GENERATECUSTOMMODELDIALOG_H
#define GENERATECUSTOMMODELDIALOG_H

#include "VideoReader.h"
#include "xlights_out.h"

//(*Headers(GenerateCustomModelDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/aui/aui.h>
#include <wx/slider.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#ifdef __WXOSX__
#include "osxMacUtils.h"
#endif

#include <wx/xml/xml.h>
#include <wx/progdlg.h>

class GenerateCustomModelDialog: public wxDialog
{
    wxXmlDocument* _network;
    wxDateTime _starttime;
    bool _continue;

    void ValidateWindow();
    void SetBulbs(bool nodes, int count, int startch, int node, int ms, int intensity, xOutput* xout);
    bool InitialiseOutputs(xOutput* xOut);
    void UpdateProgress(wxProgressDialog& pd, int totaltime);
    int FindStartFrame(VideoReader* vr);
    float CalcFrameBrightness(AVFrame* image);
    std::list<wxPoint> FindLights(wxImage& image);

#ifdef __WXOSX__
    AppNapSuspender _sleepData;
    void EnableSleepModes()
    {
        _sleepData.resume();
    }
    void DisableSleepModes()
    {
        _sleepData.suspend();
    }
#else
    void EnableSleepModes() {}
    void DisableSleepModes() {}
#endif

    public:
		GenerateCustomModelDialog(wxWindow* parent, wxXmlDocument* network, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~GenerateCustomModelDialog();

		//(*Declarations(GenerateCustomModelDialog)
		wxStaticText* StaticText9;
		wxButton* Button_Forward10Frames;
		wxSlider* Slider_LevelFilterAdjust;
		wxButton* Button_Back1Frame;
		wxStaticBitmap* StaticBitmap_Preview;
		wxAuiNotebook* AuiNotebook_ProcessSettings;
		wxButton* Button_GCM_Generate;
		wxSlider* Slider_Intensity;
		wxButton* Button_PCM_Run;
		wxSpinCtrl* SpinCtrl_NC_Count;
		wxFileDialog* FileDialog1;
		wxButton* Button_Back10Frames;
		wxPanel* Panel_BulbDetect;
		wxTextCtrl* TextCtrl_GCM_Filename;
		wxPanel* Panel_Generate;
		wxAuiNotebook* AuiNotebook1;
		wxButton* Button_SF_Next;
		wxStaticText* StaticText_StartFrameOk;
		wxButton* Button_BD_Back;
		wxRadioBox* RadioBox1;
		wxPanel* Panel_Prepare;
		wxPanel* Panel_StartFrame;
		wxSpinCtrl* SpinCtrl_StartChannel;
		wxButton* Button_BD_Next;
		wxButton* Button_Forward1Frame;
		//*)

	protected:

		//(*Identifiers(GenerateCustomModelDialog)
		static const long ID_RADIOBOX1;
		static const long ID_SPINCTRL_NC_Count;
		static const long ID_SPINCTRL_StartChannel;
		static const long ID_SLIDER_Intensity;
		static const long ID_BUTTON_PCM_Run;
		static const long ID_PANEL_Prepare;
		static const long ID_TEXTCTRL_GCM_Filename;
		static const long ID_BUTTON_GCM_SelectFile;
		static const long ID_BUTTON_GCM_Generate;
		static const long ID_STATICBITMAP_Preview;
		static const long ID_BUTTON_Back1Frame;
		static const long ID_BUTTON_Forward1Frame;
		static const long ID_BUTTON_Back10Frames;
		static const long ID_BUTTON_Forward10Frames;
		static const long ID_STATICTEXT_StartFrameOk;
		static const long ID_BUTTON_SF_Next;
		static const long ID_PANEL_StartFrame;
		static const long ID_STATICTEXT1;
		static const long ID_SLIDER_LevelFilterAdjust;
		static const long ID_BUTTON_BD_Back;
		static const long ID_BUTTON_BD_Next;
		static const long ID_PANEL_BulbDetect;
		static const long ID_AUINOTEBOOK_ProcessSettings;
		static const long ID_PANEL_Generate;
		static const long ID_AUINOTEBOOK1;
		//*)

	private:

		//(*Handlers(GenerateCustomModelDialog)
		void OnButton_GCM_SelectFileClick(wxCommandEvent& event);
		void OnTextCtrl_GCM_FilenameText(wxCommandEvent& event);
		void OnButton_GCM_GenerateClick(wxCommandEvent& event);
		void OnButton_PCM_RunClick(wxCommandEvent& event);
		void OnButton_ContinueClick(wxCommandEvent& event);
		void OnButton_BackClick(wxCommandEvent& event);
		void OnButton_NextClick(wxCommandEvent& event);
		void OnButton_SF_NextClick(wxCommandEvent& event);
		void OnButton_BD_BackClick(wxCommandEvent& event);
		void OnButton_BD_NextClick(wxCommandEvent& event);
		void OnSlider_LevelFilterAdjustCmdScroll(wxScrollEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
