import style from './UserSectionSelectPage.module.css'
import { useNavigate } from "react-router-dom"
import { useEffect, useState } from "react"
import axios from 'axios';

const UserSectionSelectPage = () => {
  const navigate = useNavigate();
  const [loading, setLoading] = useState(true);
  const [eduCount, setEduCount] = useState(null);
  const [psychoCount, setPsychoCount] = useState(null);
  const [funnyCount,  setFunnyCount] = useState(null);

  useEffect( () => {
    const fetchData = async () => {
      try {
        const response = await axios.get('http://localhost:7500/challenges');
        const dataAPI = response.data
        const testTypeArray = ["education", "psycho", "funny"]

        testTypeArray.map( (testType) => {
          const count = dataAPI.filter(item => item.testType === testType).length;
          switch (testType){
            case 'education':
              setEduCount(count)
              break

            case 'psycho':
              setPsychoCount(count)
              break

            case 'funny':
              setFunnyCount(count)
              break
            default:
          }
          return count
        })
        setLoading(false);
      } catch (error) {
        console.error('Error fetching data:', error);
      }
    };
    fetchData();
  }, [])

  if (loading){
    return (
      <div className={style.bodyStyle}></div>
    )
  }

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>
          Доступные тесты
        </div>
        <div className={style.imageBox}>
          <div>
            <img src="edu.png" alt="Education.png" onClick={ ()=>navigate('/user-subsection-select/edu')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/user-subsection-select/edu')}> Education ({eduCount}) </div>
          </div>
          <div>
            <img src="psycho.png" alt="Psychological.png" onClick={ ()=>navigate('/user-subsection-select/psycho')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/user-subsection-select/psycho')}>Psychological ({psychoCount})</div>
          </div>
          <div>
            <img src="funny.png" alt="Funny.png" onClick={ ()=>navigate('/user-subsection-select/funny')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/user-subsection-select/funny')}>Funny ({funnyCount})</div>
          </div>
        </div>
      </div>
  );
}

export default UserSectionSelectPage;
