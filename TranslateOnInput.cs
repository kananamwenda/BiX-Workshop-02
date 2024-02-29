using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TranslateOnInput : MonoBehaviour
{
    public int input=0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        float Range = Mathf.Lerp(0,2,Mathf.InverseLerp(0,1023,input));
        gameObject.transform.localPosition = new Vector3(0,0,Range);
    }
}
