package fr.planquart.jni;

import android.app.Activity;
import android.graphics.Point;
import android.os.Bundle;
import android.widget.TextView;

public class JNIActivity extends Activity
{
	static
	{
		//System.loadLibrary("stlport_shared");
		System.loadLibrary("fr_planquart_jni_JNIActivity");
	}

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.main);
		
		TextView textView = (TextView)this.findViewById(R.id.textView);
		textView.setText(this.getJNIText() + " " + this.JNIAdd(3, 4) + ". Windows size : " + this.getWindowSize());
	}
	
	native private Point getWindowSize();
	
	
	native private String getJNIText();
	
	native private int JNIAdd(int a, int b);
}
