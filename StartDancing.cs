using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class startdancing : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    void OnTriggerEnter(Collider collision){
  GameObject.FindObjectOfType<ExampleCommunicator>().startDance();
}
void OnTriggerExit(Collider collision){
   GameObject.FindObjectOfType<ExampleCommunicator>().stopDance();
}
}
