/*
 ==============================================================================

 This file was auto-generated!

 It contains the basic startup code for a Juce application.
 ==============================================================================
 */

#ifndef __PLUGINPROCESSOR_H_F70DA35D__
#define __PLUGINPROCESSOR_H_F70DA35D__

#include "../JuceLibraryCode/JuceHeader.h"

#include "ZirkConstants.h"
#include "lo.h"
#include "SoundSource.h"

//==============================================================================
/**
 The processor class of the plug in
 */
class ZirkOscjuceAudioProcessor  : public AudioProcessor,public Timer
{
public:
    //==============================================================================
    //! Constructeur
    ZirkOscjuceAudioProcessor();
    //! Destructeur
    ~ZirkOscjuceAudioProcessor();
    
    //! Called every 50ms;
    void timerCallback();
    
    
    //==============================================================================
    //! Called before playback starts, to let the filter prepare itself. 
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    //! Called after playback has stopped, to let the filter free up any resources it no longer needs. 
    void releaseResources();
    //static     int receivePositionUpdate(const char *path, const char *types, lo_arg **argv, int argc, void *data, void *user_data);
    
    //! Renders the next block. 
    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

    //==============================================================================
    //! Creates the editor and store it
    AudioProcessorEditor* createEditor();
    //! returns true if the processor has an editor
    bool hasEditor() const;

    //==============================================================================
    //! Returns the name of this processor. 
    const String getName() const;

    //! This must return the correct value immediately after the object has been created, and mustn't change the number of parameters later.
    int getNumParameters();
    //! Called by the host to find out the value of one of the filter's parameters.
    float getParameter (int index);
    //! The host will call this method to change the value of one of the filter's parameters. 
    void setParameter (int index, float newValue);
    //! Returns the name of a particular parameter. 
    const String getParameterName (int index);
    //! Returns the value of a parameter as a text string. 
    const String getParameterText (int index);
    
    //! Returns the number of input channels that the host will be sending the filter.
    const String getInputChannelName (int channelIndex) const;
    //! Returns the number of output channels that the host will be sending the filter. 
    const String getOutputChannelName (int channelIndex) const;
    //! Returns true if the specified channel is part of a stereo pair with its neighbour. 
    bool isInputChannelStereoPair (int index) const;
    //!Returns true if the specified channel is part of a stereo pair with its neighbour.
    bool isOutputChannelStereoPair (int index) const;

    //! Returns true if the processor wants midi messages. 
    bool acceptsMidi() const;
    //! Returns true if the processor produces midi messages. 
    bool producesMidi() const;
    //! Returns true if a silent input always produces a silent output.
    bool silenceInProducesSilenceOut() const;
    // We don't have sound so we just return 0.0
    double getTailLengthSeconds() const { return 0.0; }
    
    //! Projects sphere coords to polar coords 
    Point<float> domeToScreen(Point<float>);
    
    
    //==============================================================================
    //! Returns the number of preset programs the filter supports. 
    int getNumPrograms();
    //! Returns the number of the currently active program.
    int getCurrentProgram();
    //! Called by the host to change the current program. 
    void setCurrentProgram (int index);
    //! Must return the name of a given program. 
    const String getProgramName (int index);
    //! Called by the host to rename a program. 
    void changeProgramName (int index, const String& newName);


    //==============================================================================
    //! The host will call this method when it wants to save the filter's internal state, ie SAVE PRESET.
    void getStateInformation (MemoryBlock& destData);
    //! This must restore the filter's state from a block of data previously created using getStateInformation() IE RESTORE PRESET.
    void setStateInformation (const void* data, int sizeInBytes);
    
    //! returns the sources
    SoundSource* getSources(){ return _AllSources; }
    //! returns the number of sources on the screen.
    int getNbrSources() { return _NbrSources; }
    //! Set the number of sources.
    void setNbrSources(int newValue) { if ( newValue >-1 && newValue < 9) _NbrSources= newValue; }
    
    //!set wheter plug is sending osc messages to zirkonium
    void setIsOscActive(bool isOscActive);
    //!wheter plug is sending osc messages to zirkonium
    bool getIsOscActive();

    //!set wheter plug is sending osc messages to zirkonium
    void setIsSpanLinked(bool isSpanLinked);
    //!wheter plug is sending osc messages to zirkonium
    bool getIsSpanLinked();

    //!set wheter programmed trajectories are written in sync with host tempo
    void setIsSyncWTempo(bool isSyncWTempo);
    //!get wheter programmed trajectories are written in sync with host tempo
    bool getIsSyncWTempo();
    
    //!set wheter to write programmed trajectory on next host play
    void setIsWriteTrajectory(bool isWriteTrajectory);
    //!get wheter to write programmed trajectory on next host play
    bool getIsWriteTrajectory();
    
    void setSelectedSourceForTrajectory(int iSelectedSource);
    
    int getSelectedSourceForTrajectory();
    
    //! return the tab position of the selectedSource 
    int getSelectedSource() { return _SelectedSource; }
    //! Set the selected source 
    void setSelectedSource(int selected){ if ( selected >-1 && selected < 8) _SelectedSource= selected;};
    //! Returns the Osc Port for the Zirkonium sending
    int getOscPortZirkonium(){return _OscPortZirkonium;}
    //! Retunrs the Osc port where the iPad messages are received
    String getOscPortIpadIncoming(){ return _OscPortIpadIncoming;}
    //! Returns the Osc iPad port where we send messages
    String getOscPortIpadOutgoing(){ return _OscPortIpadOutgoing;}
    //! Returns the iPad's IP address.
    String getOscAddressIpad() {return _OscAddressIpad; }
    
    enum ParameterIds
    {
        ZirkOSC_Azim_ParamId = 0,
        ZirkOSC_Elev_ParamId,
        ZirkOSC_AzimSpan_ParamId,
        ZirkOSC_ElevSpan_ParamId,
        ZirkOSC_Gain_ParamId,
        ZirkOSC_Azim_ParamId_1,
        ZirkOSC_Elev_ParamId_1,
        ZirkOSC_AzimSpan_ParamId_1,
        ZirkOSC_ElevSpan_ParamId_1,
        ZirkOSC_Gain_ParamId_1,
        ZirkOSC_Azim_ParamId_2,
        ZirkOSC_Elev_ParamId_2,
        ZirkOSC_AzimSpan_ParamId_2,
        ZirkOSC_ElevSpan_ParamId_2,
        ZirkOSC_Gain_ParamId_2,
        ZirkOSC_Azim_ParamId_3,
        ZirkOSC_Elev_ParamId_3,
        ZirkOSC_AzimSpan_ParamId_3,
        ZirkOSC_ElevSpan_ParamId_3,
        ZirkOSC_Gain_ParamId_3,
        ZirkOSC_Azim_ParamId_4,
        ZirkOSC_Elev_ParamId_4,
        ZirkOSC_AzimSpan_ParamId_4,
        ZirkOSC_ElevSpan_ParamId_4,
        ZirkOSC_Gain_ParamId_4,
        ZirkOSC_Azim_ParamId_5,
        ZirkOSC_Elev_ParamId_5,
        ZirkOSC_AzimSpan_ParamId_5,
        ZirkOSC_ElevSpan_ParamId_5,
        ZirkOSC_Gain_ParamId_5,
        ZirkOSC_Azim_ParamId_6,
        ZirkOSC_Elev_ParamId_6,
        ZirkOSC_AzimSpan_ParamId_6,
        ZirkOSC_ElevSpan_ParamId_6,
        ZirkOSC_Gain_ParamId_6,
        ZirkOSC_Azim_ParamId_7,
        ZirkOSC_Elev_ParamId_7,
        ZirkOSC_AzimSpan_ParamId_7,
        ZirkOSC_ElevSpan_ParamId_7,
        ZirkOSC_Gain_ParamId_7,
        ZirkOSC_MovementConstraint_ParamId,
        ZirkOSC_isSpanLinked_ParamId,
        ZirkOSC_isOscActive_ParamId,
        ZirkOSC_SelectedTrajectory_ParamId,
        ZirkOSC_TrajectoryCount_ParamId,
        ZirkOSC_TrajectoriesDuration_ParamId,
        ZirkOSC_SyncWTempo_ParamId,
        ZirkOSC_WriteTrajectories_ParamId,
        totalNumParams
    };
    //! Send the current state to all the iPad and Zirkonium
    void sendOSCValues();
    
    //! Getter constrain type as integer, since parameters need to be stored as floats [0,1]
    int getSelectedMovementConstraintAsInteger();
    
    //! Getter for trajectory as integer, since parameters need to be stored as floats [0,1]
    int getSelectedTrajectoryAsInteger();

    //returns info about the current host position, tempo, etc
    juce::AudioPlayHead::CurrentPositionInfo &getCurrentPlayHeadInfo();
    
    //! Retunrs true if the Editor has to refresh the Gui.
    bool hasToRefreshGui(){return _RefreshGui;};
    //! If you want to refresh the Gui from the Processor.
    void setRefreshGui(bool gui) { _RefreshGui = gui;};
    //! Change the sending OSC port of the zirkonium
    void changeZirkoniumOSCPort(int newPort);
    //! Send the configuration to the iPad (assignment Position -> id, nbr source)
    void sendOSCConfig();
    //! Send the movement type, selected constrain.
    void sendOSCMovementType();
    //! Change the sending OSC port of the iPad
    void changeOSCSendIPad(int newPort, String newAddress);
    //! Change the receiving OSC port (server).
    void changeOSCReceiveIpad(int port);
    //! Returns the Editor.
    AudioProcessorEditor* getEditor() {return _Editor;};
    //! Set the width that the UI was last set to
    void setLastUiWidth(int lastUiWidth);
    //! Get the width that the UI was last set to
    int getLastUiWidth();
    //! Set the height that the UI was last set to
    void setLastUiHeight(int lastUiHeight);
    //! Return the height that the UI was last set to
    int getLastUiHeight();
    //! Return the size of the dome radius
    int getDomeRadius();
    //! Set the size of the dome radius
    void setDomeRadius(int iNewRadius);
    //radius of the dome
    static int s_iDomeRadius;
    
    
private:
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ZirkOscjuceAudioProcessor)
    //! Whether the editor has to refresh the GUI
    bool _RefreshGui = false;
    //! Current number of sources on the screnn
    int _NbrSources;
    //! float ID of the selected movement constraint
    float _SelectedMovementConstraint;
    //! float ID of the selected trajectory
    float _SelectedTrajectory;
    //! Tab position of the selected source
    int _SelectedSource;
    //! Osc port to send to the Zirkonium 
    int _OscPortZirkonium;
    //! The editor
    AudioProcessorEditor* _Editor;
    //! Sources array
    SoundSource _AllSources [8];
    //! Osc Sever thread (receiving)
    lo_server_thread _St;
    //! Zirkonium OSC address (sending)
    lo_address _OscZirkonium;
    //! Ipad OSC address (sending)
    lo_address _OscIpad;
    //! Outgoing port to the iPad 
    String _OscPortIpadOutgoing;
    //! iPad address
    String _OscAddressIpad;
    //! Zirkonium incoming port
    String _OscPortIpadIncoming;
    //! last saved ui width
    int _LastUiWidth;
    //! last saved ui height
    int _LastUiHeight;
    //! Whether we're sending OSC messages to the zirkonium
    bool _isOscActive;
    //! If the span are linked
    bool _isSpanLinked;
    //! Number of trajectories to draw in trajectory section
    int _TrajectoryCount;
    //! Duration of trajectory movement
    double _TrajectoriesDuration;
    
    //! whether we drew the whole trajectory
    bool _TrajectoryAllDrawn;
    
    double _TrajectoryBeginTime;
    
    float _TrajectoryInitialValue;
    
    double _TrajectorySingleLength;
    
    
    bool _TrajectoryJustCompletedSingle;
    
    int iProcessBlockCounter;
    
    //!Whether to sync trajectories with tempo
    bool _isSyncWTempo;
    //!Whether to write trajectory or not
    bool _isWriteTrajectory;
    
    int _SelectedSourceForTrajectory;
    
    bool _WasPlayingOnPrevFrame;
    
    bool _JustsEndedPlaying;
    
    //contains the information returned from the playHead
    juce::AudioPlayHead::CurrentPositionInfo _CurrentPlayHeadInfo;

};

#endif  // __PLUGINPROCESSOR_H_F70DA35D__
