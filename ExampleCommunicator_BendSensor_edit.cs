using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Sngty;

public class ExampleCommunicator : MonoBehaviour
{
    public SingularityManager mySingularityManager;
    DeviceSignature myDevice = new DeviceSignature();

    // Testing Stuff
 //   public GameObject receivingMessageIndicatorLight;

    public GameObject UIInterfacePanel;
    public TMPro.TMP_Text _debugText;
    
    public  TranslateOnInput sphere ;
    // Start is called before the first frame update
    void Start()
    {

        List<DeviceSignature> pairedDevices = mySingularityManager.GetPairedDevices();


        //If you are looking for a device with a specific name (in this case exampleDeviceName):
        for (int i = 0; i < pairedDevices.Count; i++)
        {
            //_debugText.text = pairedDevices[i].name.ToString();

            if ("ESP32_Trish".Equals(pairedDevices[i].name))
            //if (pairedDevices[i].name == "ESP32_Trish")
            {
                myDevice = pairedDevices[i];
                _debugText.text = "Found "+ pairedDevices[i].mac.ToString();
                mySingularityManager.ConnectToDevice(myDevice);
                break;
            } else {
                _debugText.text = "No match";
            }
        }

        if (!myDevice.Equals(default(DeviceSignature)))
        {
            //Do stuff to connect to the device here
        }

    }

    public void onConnected()
    {
        Debug.Log("Connected to device!");
        _debugText.text = "Connected!";
        mySingularityManager.sendMessage("1", myDevice);
  //      receivingMessageIndicatorLight.SetActive(false);
    }

    public void onMessageRecieved(string message)
    {
        sphere.input = int.Parse(message);
    //     Debug.Log("Message recieved from device: " + message);
    //     _debugText.text = message;
    //     UIInterfacePanel.SetActive(false);
    //  //   receivingMessageIndicatorLight.SetActive(false);


    //     if ("1".Equals(message)){
    //  //       receivingMessageIndicatorLight.SetActive(true);

    //     } else {
    //  //       receivingMessageIndicatorLight.SetActive(false);

    //     }
        
    }

    public void onError(string errorMessage)
    {
        Debug.LogError("Error with Singularity: " + errorMessage);
        _debugText.text = "Error with Singularity" + errorMessage;
    }
// public void startDance(){
  //    mySingularityManager.sendMessage("dance\n", myDevice);
 }
//public void stopDance(){
  //   mySingularityManager.sendMessage("stop\n", myDevice);
//}
//}