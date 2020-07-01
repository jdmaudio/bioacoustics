function output = threshold_detection(wave)

    threshold = 5;
    channel = 'left';
    time_exp = 1;
    min_dur = 1;
    max_dur = 20;
    min_TBE = 10;
    max_TBE = 5000;
    EDG = 0.996;
    LPF = 120000;
    HPF = 20000;
    FFT_size = 256;
    FFT_overlap = .875;
    start_thr = 12;
    end_thr = 30;
    SNR_thr = 6;
    angle_thr = 45;
    duration_thr = 44;
    NWS = 100;
    KPE = 0.00001;
    KME = 0.0001;
    settings = 0;
    acoustic_feat = 1;
    metadata = 0;
    spectro_dir = '';
    time_scale = 0.1;
    ticks = 1;


  if (ischar(wave))
    samples = audioread(wave,'native');
    info = audioinfo(wave);
  end
  
  [filepath,filename,ext] = fileparts(wave); 
  
  sample_rate = info.SampleRate * time_exp
  bit_depth = info.BitsPerSample;
  
  output =  MyMEXFunction(samples, sample_rate, threshold, min_dur, max_dur,...
   min_TBE, max_TBE, EDG, LPF, HPF, duration_thr, SNR_thr, angle_thr, FFT_size, FFT_overlap, ...
   start_thr, end_thr, NWS,KPE,KME);

end

